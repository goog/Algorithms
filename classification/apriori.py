import itertools

def apriori(tuples,minSUP):
    ## tuples is a list
    #the itemset define as a li (sorted)
    ###init  itemsets
    items = set()
    item = set()
    for j in tuples:
        for k in j:
            item.add(k)
    print "there is %s items in list" %(len(item))
    print "item",item

    for i in item:
        items.add(i)   ##  now a itemset is a string
    print "the length of C1 is %s" %(len(items))

    
    while(True):

        ##  COMPUTE Lk-1
        ## compute the support 
        supports = {}
        for i in items:
            j = set(i.split())  ## convert string i to a set
            for k in tuples:
                if j.issubset(k):
                    #print ilist,type(ilist)
                    if supports.get(i):
                        supports[i]+=1
                    else:
                        supports[i]=1
                        
        for k in supports.keys():
            if supports[k]< minSUP:
                del supports[k]
        if supports is None:
            print "no supports "
            break


        ### join, generate Ck
        Ck = set()
        #print "supports.keys()",type(supports.keys())
        a = set(supports.keys())
        b = a.copy()
        for i in a:
            b.remove(i)
            for j in b:    ### get two different eles from the set
                aLIST = i.split()
                bLIST = j.split()
                if len(aLIST) == len(bLIST) and aLIST != bLIST and aLIST[:-1] ==bLIST[:-1]:   ####(k-1) in common in order
                    ck = aLIST;ck.append(bLIST[-1])
                    ck.sort()
                    Ck.add(' '.join(ck))

        #### prune
        Ck1 = Ck.copy()
        for i in Ck:
            j = i.split()
            cb = itertools.combinations(j,len(j)-1)
            print "the length of cb",type(cb)
            print "the cb is :",cb
            for k in cb:
                print "the combination :",k,type(k)
                klist = list(k)
                klist.sort()
                if supports.get(' '.join(klist)) is None:
                    Ck1.remove(i)
                    break
                elif supports[' '.join(klist)] < minSUP:
                    Ck1.remove(i)
                    break
                
        if Ck1 is None:
            print "items is:",items
            break
        items = Ck1    ##  itemset Lk

    print "over"

if  __name__ == '__main__':
    tuples=[set(['I1', 'I2', 'I5']),
            set(['I2', 'I4']),
            set(['I2', 'I3']),
            set(['I1', 'I2', 'I4']),
            set(['I1', 'I3']),
            set(['I2', 'I3']),
            set(['I1', 'I3']),
            set(['I1', 'I2', 'I3', 'I5']),
            set(['I1', 'I2', 'I3'])
        ]
    apriori(tuples,2)
