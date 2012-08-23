#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Conditional Random Field
# This code is available under the MIT License.
# (c)2010-2011 Nakatani Shuyo / Cybozu Labs Inc.
# reniced by chengjie @GDUT.dmir. Thank my tutor Mr Hao.

import numpy
from scipy import maxentropy

def logdotexp_vec_mat(loga,logM):
    return numpy.array([maxentropy.logsumexp(loga + x) for x in logM.T], copy=False)
    #return numpy.array([numpy.log(numpy.dot(numpy.exp(loga),numpy.exp(x))) for x in logM.T], copy=False)
    #log(a*M) -->log alpha  .T :transpose

def logdotexp_mat_vec(logM, logb):
    return numpy.array([maxentropy.logsumexp(x + logb) for x in logM], copy=False)

# convert to a list
def flatten(x):
    a = []
    for y in x: a.extend(flatten(y) if isinstance(y, list) else [y])
    return a

# rethink, fv: features about a training sample (like a sentence)

class FeatureVector(object):
    def __init__(self, features, xlist, ylist=None):
        '''intermediates of features (sufficient statistics like)'''
        flist = features.features_edge  # transfer features function
        glist = features.features       # state feature function
        self.K = len(features.labels)   # length of all labels sequence
        
        # expectation of features under empirical distribution (if ylist is specified)
        # ylist :label sequence
        if ylist:
            self.Fss = numpy.zeros(features.size(), dtype=int)  #features size,a large number
            for y1,y2,x in zip(["start"] + ylist, ylist + ["end"],xlist):
                self.Fss[:len(flist)] += [f(y1,y2,x) for f in flist]  # adds edge_feature values
            for y1,x1 in zip(ylist,xlist):
                self.Fss[len(flist):] += [g(x1,y1) for g in glist]
        #Fss is the numerical array including all features,empirical distribution

        # index list of ON values of edge features //f_value=1 , the n is for n samples
        self.Fon = [] # (n, #f, indexes)
        self.Fmat = [] # (n, K, #f, K)-matrix
        self.Gmat = [] # (n, #g, K)-matrix
        for x in xlist:
            mt = numpy.zeros((len(glist), self.K), dtype=int) # #g rows K clos
            for j, g in enumerate(glist): 
                mt[j] = [g(x, y) for y in features.labels]
                #sparse,check wether per position x and label y meet the g feature function
            self.Gmat.append(mt)         # g(y_i,x,i) one feature function(ff) on each position
            self._calc_fmlist(features,flist,x) # fmlist depends on x_i 
        
        

    # fmlist: generate stransfer features matrix from training data
    def _calc_fmlist(self,features,flist,x):
        fmlist = []
        f_on = [[] for f in flist]  # for a feature_edge function,
        for k1, y1 in enumerate(features.labels):  # consider all y_,y combinations
            mt = numpy.zeros((len(flist), self.K), dtype=int)
            for j, f in enumerate(flist):
                mt[j] = [f(y1,y2,x) for y2 in features.labels]  # sparse
                # mt[j] , there exist several 1s, T'sS several directions to go
                f_on[j].extend([k1 * self.K + k2 for k2, v in enumerate(mt[j]) if v == 1])
                # record the positon at m_i for those transfer edges exist
            fmlist.append(mt)    # every x_i generates a mt.  flist:(K, #f, K)-matrix
        self.Fmat.append(fmlist) # execute multitupe times 
        self.Fon.append(f_on)
    
    
    # dotproduct form of the model. theta:learned parameter, Fss:F(y,x),global features
    def cost(self, theta):
        return numpy.dot(theta, self.Fss)  # formula 11.19
    
    # M_i formula 11.21
    def logMlist(self, theta_f, theta_g):
        '''for independent fmlists on x_i'''
        fv = numpy.zeros((self.K, self.K))     #has the shape
        for j,fm in enumerate(self.Fmat[0]):   #Fmat[0]: fmlist(K, #f, K)-matrix.
            fv[j] = numpy.dot(theta_f, fm)     #fv[j]:list  w*F
        # use the same fv matrix
        return [fv + numpy.dot(theta_g, gm) for gm in self.Gmat] + [fv]


class Features(object):
    def __init__(self, labels): # labels is list
        self.features = []
        self.features_edge = []
        self.labels = ["start","stop"] + flatten(labels)

    def start_label_index(self):
        return 0
    def stop_label_index(self):
        return 1
    def size(self):
        return len(self.features) + len(self.features_edge)
    def size_edge(self):
        return len(self.features_edge)
    def id2label(self, list):
        return [self.labels[id] for id in list]
    # add feature functions
    def add_feature(self, f):
        self.features.append(f)
    def add_feature_edge(self, f):
        self.features_edge.append(f)

class CRF(object):
    def __init__(self, features, regularity, sigma=1):
        self.features = features
        if regularity == 0:
            self.regularity = lambda w:0
            self.regularity_deriv = lambda w:0
        elif regularity == 1:
            self.regularity = lambda w:numpy.sum(numpy.abs(w)) / sigma
            self.regularity_deriv = lambda w:numpy.sign(w) / sigma #the deriv
        else:
            v = sigma ** 2
            v2 = v * 2
            self.regularity = lambda w:numpy.sum(w ** 2) / v2
            self.regularity_deriv = lambda w:numpy.sum(w) / v

    def random_param(self):
        return numpy.random.randn(self.features.size())

    # forward algorithm
    def logalphas(self, Mlist):
        logalpha = Mlist[0][self.features.start_label_index()] # alpha(1),logalphas starts with alpha(1)
        logalphas = [logalpha] 
        for logM in Mlist[1:]:
            logalpha = logdotexp_vec_mat(logalpha, logM)
            logalphas.append(logalpha)
        return logalphas
    
    # backward algorithm 
    def logbetas(self, Mlist):
        logbeta = Mlist[-1][:, self.features.stop_label_index()]  # beta(n)
        logbetas = [logbeta]
        for logM in Mlist[-2::-1]:
            logbeta = logdotexp_mat_vec(logM, logbeta)
            logbetas.append(logbeta)
        return logbetas[::-1]  #adjust the order


    def likelihood(self, fvs, theta):
        '''conditional log likelihood log p(Y|X)'''
        n_fe = self.features.size_edge()
        t1, t2 = theta[:n_fe], theta[n_fe:] # two kinds features
        stop_index = self.features.stop_label_index()

        likelihood = 0
        # fv: FeatureVector F(y_i,x_i)
        for fv in fvs: # on book N is #fvs
            logMlist = fv.logMlist(t1, t2)
            logZ = self.logalphas(logMlist)[-1][stop_index] #Z(x) b 11.31 below
            likelihood += fv.cost(theta) - logZ             #b 11.4.1  for N (x,y) samples, fv: f_k(x,y)
        return likelihood - self.regularity(theta)          # regularity

    def gradient_likelihood(self, fvs, theta):   
        n_fe = self.features.size_edge() # number of features on edge
        t1, t2 = theta[:n_fe], theta[n_fe:]
        stop_index = self.features.stop_label_index()
        start_index = self.features.start_label_index()

        grad = numpy.zeros(self.features.size())
        for fv in fvs:
            logMlist = fv.logMlist(t1, t2)
            logalphas = self.logalphas(logMlist)
            logbetas = self.logbetas(logMlist)
            logZ = logalphas[-1][stop_index]

            grad += numpy.array(fv.Fss, dtype=float) # empirical expectation

            # expection: b 11.34
            expect = numpy.zeros_like(logMlist[0])
            #print 'the shape of expect:',expect.shape the shape of expect: (18, 18)
            for i in range(len(logMlist)):
                if i == 0:
                    expect[start_index] += numpy.exp(logalphas[i] + logbetas[i+1] - logZ)
                    # alphas[i]*betas[i+1]/Z
                elif i < len(logbetas) - 1:
                    a = logalphas[i-1][:, numpy.newaxis] # becomes 2D array
                    #expect += numpy.exp(logMlist[i] + a + logbetas[i+1] - logZ)
                    expect += numpy.exp(logMlist[i] + a + logbetas[i] - logZ)
                else:
                    expect[:, stop_index] += numpy.exp(logalphas[i-1] + logbetas[i] - logZ)

            # there is product feature functions.
            for k, indexes in enumerate(fv.Fon[0]): # edge_feature exists,
                grad[k] -= numpy.sum(expect.take(indexes)) # take:Take elements from an array along an axis

            for i, gm in enumerate(fv.Gmat):
                # probability of P(yi|x) p_yi = numpy.exp(logalphas[i] + logbetas[i] - logZ)
                # gm * p_yi sum at each row
                grad[n_fe:] -= numpy.sum(gm * numpy.exp(logalphas[i] + logbetas[i+1] - logZ),axis=1)
            # why fm dont product probability. 
                

        return grad - self.regularity_deriv(theta)

    # learning algorithm using BFGS algorithm
    def inference(self, fvs, theta):
        from scipy import optimize
        likelihood = lambda x:-self.likelihood(fvs, x)# replace theta with x.
        likelihood_deriv = lambda x:-self.gradient_likelihood(fvs, x)
        return optimize.fmin_bfgs(likelihood, theta, fprime=likelihood_deriv)
        #fmin_bfgs(f, x0, fprime=None)
        ''' f : callable f(x,*args)
           x0 : ndarray Initial guess.
        fprime: optional Gradient of f.'''

    # veterbi algorithm to predict the sequence.
    def tagging(self, fv, theta):
        n_fe = self.features.size_edge() # number of features on edge
        logMlist = fv.logMlist(theta[:n_fe], theta[n_fe:])
        logalphas = self.logalphas(logMlist)
        logZ = logalphas[-1][self.features.stop_label_index()]
        #
        delta = logMlist[0][self.features.start_label_index()]  #alpha(1)
        argmax_y = []
        # ? Multiple products
        for logM in logMlist[1:]:
            h = logM + delta[:, numpy.newaxis]
            argmax_y.append(h.argmax(0)) # argmax:return indices of in each column
            delta = h.max(0)  # return max row
        Y = [delta.argmax()] # 
        for a in reversed(argmax_y):
            Y.append(a[Y[-1]])
        return Y[0] - logZ, Y[::-1]

    def tagging_verify(self, fv, theta):
        '''verification of tagging'''
        n_fe = self.features.size_edge() # number of features on edge
        logMlist = fv.logMlist(theta[:n_fe], theta[n_fe:])
        N = len(logMlist) - 1 # the length of a sequence
        K = logMlist[0][0].size #

        ylist = [0] * N
        max_p = -1e9
        argmax_p = None
        while True:
            logp = logMlist[0][self.features.start_label_index(), ylist[0]]
            for i in range(len(ylist)-1):
                logp += logMlist[i+1][ylist[i], ylist[i+1]]
            logp += logMlist[N][ylist[N-1], self.features.stop_label_index()]
            print ylist, logp
            if max_p < logp:
                max_p = logp
                argmax_p = ylist[:]

            for k in range(N-1,-1,-1):
                if ylist[k] < K-1:
                    ylist[k] += 1
                    break
                ylist[k] = 0
            else:
                break
        return max_p, argmax_p



def main():
    def load_data(data):
        texts = []
        labels = []
        text = []
        data = "\n" + data + "\n"
        for line in data.split("\n"):
            line = line.strip()
            if len(line) == 0:
                if len(text)>0:
                    texts.append(text)
                    labels.append(label)
                text = []
                label = []
            else:
                token, info, chunk = line.split()
                text.append((token, info))
                label.append(chunk)
        return (texts, labels)

    texts, labels = load_data("""
    This DT B-NP
    temblor-prone JJ I-NP
    city NN I-NP
    dispatched VBD B-VP
    inspectors NNS B-NP
    , , O
    firefighters NNS B-NP
    and CC O
    other JJ B-NP
    earthquake-trained JJ I-NP
    personnel NNS I-NP
    to TO B-VP
    aid VB I-VP
    San NNP B-NP
    Francisco NNP I-NP
    . . O

    He PRP B-NP
    reckons VBZ B-VP
    the DT B-NP
    current JJ I-NP
    account NN I-NP
    deficit NN I-NP
    will MD B-VP
    narrow VB I-VP
    to TO B-PP
    only RB B-NP
    # # I-NP
    1.8 CD I-NP
    billion CD I-NP
    in IN B-PP
    September NNP B-NP
    . . O

    Meanwhile RB B-ADVP
    , , O
    overall JJ B-NP
    evidence NN I-NP
    on IN B-PP
    the DT B-NP
    economy NN I-NP
    remains VBZ B-VP
    fairly RB B-ADJP
    clouded VBN I-ADJP
    . . O

    But CC O
    consumer NN B-NP
    expenditure NN I-NP
    data NNS I-NP
    released VBD B-VP
    Friday NNP B-NP
    do VBP B-VP
    n't RB I-VP
    suggest VB I-VP
    that IN B-SBAR
    the DT B-NP
    U.K. NNP I-NP
    economy NN I-NP
    is VBZ B-VP
    slowing VBG I-VP
    that DT B-ADVP
    quickly RB I-ADVP
    . . O
    """)

    #print "texts",texts
    #print "labels",labels each sentence has a label list:['B-NP', 'I-NP', 'I-NP', ... , 'I-NP', 'O']
    
    test_texts, test_labels = load_data("""
    Rockwell NNP B-NP
    said VBD B-VP
    the DT B-NP
    agreement NN I-NP
    calls VBZ B-VP
    for IN B-SBAR
    it PRP B-NP
    to TO B-VP
    supply VB I-VP
    200 CD B-NP
    additional JJ I-NP
    so-called JJ I-NP
    shipsets NNS I-NP
    for IN B-PP
    the DT B-NP
    planes NNS I-NP
    . . O
    """)

    #print 'labels: ',labels,'the length is:',len(labels)
    features = Features(labels)
    #print 'features.labels:',features.labels  # a long label sequence
    #print 'the length of features.labels',len(features.labels)
    tokens = dict([(i[0],1) for x in texts for i in x]).keys() # extract all tokens by dictionary.
    # is a list, can improve to dict.
    infos = dict([(i[1],1) for x in texts for i in x]).keys()
    pre_y =''
    for j,label in enumerate(features.labels):  #label for a line
        for token in tokens:
            features.add_feature( lambda x, y, l=label, t=token: 1 if y==l and x[0]==t else 0 )
            # def self.features.append(f) .
        for info in infos:
            features.add_feature( lambda x, y, l=label, i=info: 1 if y==l and x[1]==i else 0 )
        if j:
            features.add_feature_edge( lambda y_, y,x,p=pre_y,l=label: 1 if y_==p and y==l else 0 )
        pre_y=label
            

    fvs = [FeatureVector(features, x, y) for x, y in zip(texts, labels)]
    fv = fvs[0]
    text_fv = FeatureVector(features, test_texts[0]) # text sequence without labels

    crf = CRF(features, 2)  # regularity =2
    theta = crf.random_param()

    #print "features:", features.size()
    #print "labels sequence which have met:", len(features.labels)
    #labels(flattened) sequence which have met: 63
    #print features.labels ['start', 'stop', 'B-NP',.....,'O']
    

    print "log likelihood:", crf.likelihood(fvs, theta)
    prob, ys = crf.tagging(text_fv, theta)
    print "tagging:", prob, features.id2label(ys)

    theta = crf.inference(fvs, theta) # learn parameters
    print "theta:", theta   
    print "log likelihood:", crf.likelihood(fvs, theta)
    prob, ys = crf.tagging(text_fv, theta)
    print "tagging:", prob, zip(test_texts[0], test_labels[0], features.id2label(ys))

if __name__ == "__main__":
    main()
