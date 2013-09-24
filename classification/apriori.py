import itertools

def apriori(tuples,minSUP):
    ## candidate k-itemset
    items = set()   ##  init C1
    item = set()   ## one item set
    
    for j in tuples:
        for k in j:
            item.add(k)
    print "there are %s unique items in the list" %(len(item))

    ## construct the C1
    for i in item:
        items.add(i)
    print "the length of C1 is %s" %(len(items))

    
    while(True):
        ##  COMPUTE Lk-1
        supports = {}
        for i in items:  ## i is a string of the sorted itemset
            j = set(i.split())  ## convert string i into a set
            for k in tuples:    ## k is a shopping list set
                if j.issubset(k):
                    if supports.get(i):
                        supports[i]+=1
                    else:
                        supports[i]=1
                        
        for k in supports.keys():
            if supports[k]< minSUP:
                del supports[k]
        if supports is None:
            print "The supports is empty."
            break


        ## generate Ck
        Ck = set()
        a = set(supports.keys())  ## L(k-1)
        b = a.copy()
        
        for i in a:
            b.remove(i)
            for j in b:    ## get two elements from the set a
                aLIST = i.split()
                bLIST = j.split()
                ## requires (k-1) elements in common
                inter = set(aLIST) & set(bLIST)
                union = set(aLIST) | set(bLIST)
                if len(aLIST) == len(bLIST) and (len(inter) == len(aLIST)-1 ) and len(union - inter)==2 :
                    ck = list(union)
                    ck.sort()
                    Ck.add(' '.join(ck))

        #### prune
        Ck1 = Ck.copy()
        for i in Ck:
            j = i.split()
            cb = itertools.combinations(j,len(j)-1)
            for k in cb:
                klist = list(k)
                klist.sort()
                if supports.get(' '.join(klist)) is None:
                    Ck1.remove(i)
                    break
                elif supports.get(' '.join(klist)) < minSUP:
                    Ck1.remove(i)
                    break
                
        if Ck1:
            items = Ck1
        else:
            print "items is:",items
            break
        

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
