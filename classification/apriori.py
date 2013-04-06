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


        ## compute the support 
        supports = {}
        for i in items:
            i = set(i.split())  ## convert i to a set
            for j in tuples:
                if i.issubset(j):
                    ilist = list(i)
                    ilist.sort()
                    #print ilist,type(ilist)
                    if supports.get(' '.join(ilist)):
                        supports[' '.join(ilist)]+=1
                    else:
                        supports[' '.join(ilist)]=1
        ##get support more than fixed value
        for k in supports.keys():
            if supports[k]< minSUP:
                del supports[k]
        if supports is None:
            print "no supports "
            break


        ### join, generate Ck
        Ck = set()
        a = set(supports.keys())
        b = a.copy()
        for i in a:
            b.remove(i)
            for j in b:    ### get two different eles from the list
                aLIST = i.split()
                bLIST = j.split()
                aSET = set(aLIST)
                bSET = set(bLIST)
                if len(aSET & bSET) == len(aLIST)-1:
                    ck = list(aSET|bSET)
                    ck.sort()
                    Ck.add(' '.join(ck))

        #### prune
        Ck1 = Ck.copy()
        for i in Ck:
            i = i.split()
            cb = itertools.combinations(i,len(i)-1)
            for j in cb:
                print "test",j,type(j)
                jlist = list(j)
                jlist.sort()
                if supports.get(' '.join(jlist)) is None:
                    Ck1.remove(' '.join(i))
                    break
                elif supports[' '.join(jlist)] < minSUP:
                    Ck1.remove(' '.join(i))
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
