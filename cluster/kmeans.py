import random

def kmeans(k,data):
    ### the data :::list
    centroidLIST= []
    initID =  random.sample(range(len(data)),k)
    cluster = []
    for i in range(k):
        cluster.append(set())
        centroidLIST.append(data[initID[i]])   ### initial cluster center
    

    while(True):
        
        ####  reassign the points
        for i in data:
            min = float('inf'); index = 0 
            for j,l in enumerate(centroidLIST):
                distance = (i[0]-l[0]) **2 + (i[1]-l[1]) ** 2
                if distance < min:
                    min = distance
                    index = j 
            cluster[index].add(i)

        oldCENTROID = centroidLIST
        #####  compute the centroid
        centroidLIST = []
        for i in range(k):
            ### cluster[i]
            x = 0;y = 0
            n = len(cluster[i])
            for j in cluster[i]:
                x+=j[0]
                y+=j[1]
            x/=float(n)
            y/=float(n)
            centroidLIST.append((x,y))
        if oldCENTROID == centroidLIST:
            for i in range(k):
                print "the %s cluster is :" % (i+1)
                print cluster[i]
            break
    
        ## clear the cluster data
        for i in range(k):
            cluster.append(set())


k =2  
data = [(1,1),(1,2),(1,3),(4,2),(4,3),(4,4)]
kmeans(k,data)
