import numpy as np
from scipy.sparse import csc_matrix

def pageRank(G, s = .85, maxerr = .001):
    '''
    Computes the pagerank for each of the n states.

    Used in webpage ranking and text summarization using unweighted
    or weighted transitions respectively.'''
   
    n = G.shape[0]

    # transform G into markov matrix M
    M = csc_matrix(G,dtype=np.float)
    # sum(1):sum of each row
    rsums = np.array(M.sum(1))[:,0]
    # rsums : [ 1.  2.  3.  2.  1.  2.  3.]
    ri, ci = M.nonzero()   #Return the indices of non-zero
    M.data /= rsums[ri]
    # bool array of sink states, rsums==0
    sink = rsums==0
    

    # Compute pagerank r until we converge
    ro, r = np.zeros(n), np.ones(n)
    while np.sum(np.abs(r-ro)) > maxerr:
        ro = r.copy()
        # calculate each pagerank at a time
        for i in xrange(0,n):
            # inlinks of state i
            Ii = np.array(M[:,i].todense())[:,0]  # select i column
            print Ii
            # account for sink states
            Si = sink / float(n)
            # account for teleportation to state i
            Ti = np.ones(n) / float(n)
            r[i] = ro.dot( Ii*s + Si*s + Ti*(1-s) )

    # return normalized pagerank
    return r/sum(r)




if __name__=='__main__':
    G = np.array([[0,0,1,0,0,0,0],
                  [0,1,1,0,0,0,0],
                  [1,0,1,1,0,0,0],
                  [0,0,0,1,1,0,0],
                  [0,0,0,0,0,0,1],
                  [0,0,0,0,0,1,1],
                  [0,0,0,1,1,0,1]])

    print pageRank(G,s=.86)
