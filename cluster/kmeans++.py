import random
'''
The exact algorithm is as follows:

    1,Choose one center uniformly at random from among the data points.
    2,For each data point x, compute D(x), the distance between x and the nearest center that has already been chosen.
    3,Choose one new data point at random as a new center, using a weighted probability distribution
      where a point x is chosen with probability proportional to D(x)**2.
    4,Repeat Steps 2 and 3 until k centers have been chosen.
    5,Now that the initial centers have been chosen, proceed using standard k-means clustering.

'''

def initialize(X, K):
    C = [X[0]]
    for k in range(1, K):
        D2 = scipy.array([min([scipy.inner(c-x,c-x) for c in C]) for x in X])
        probs = D2/D2.sum()   #### 
        cumprobs = probs.cumsum()
        r = scipy.rand()
        for j,p in enumerate(cumprobs):
            if r < p:
                i = j
                break
        C.append(X[i])
    return C

    #...
    
##http://stackoverflow.com/questions/5466323/how-exactly-does-k-means-work

k =2  
data = [(1,1),(1,2),(1,3),(4,2),(4,3),(4,4)]
kmeans(k,data)
