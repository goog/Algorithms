from numpy import *

def pagerank(d,v_quadratic_error):
    M= array([[0,0,0,0,1],
              [0.5,0,0,0,0],
              [0.5,0,0,0,0],
              [0,1,0.5,0,0],
              [0,0,0.5,1,0]])
    
    N=M.shape[1]
    v=random.rand(N,1)
    v=v/linalg.norm(v)
    a=array([[inf]]);last_v = dot(ones((N,1)),a)
    M_hat=(d * M)+(((1-d)/N)*ones((N,N)))
    i=0
    while(linalg.norm(v - last_v) > v_quadratic_error):
        i+=1
        last_v = v
        v = dot(M_hat,v)
        v = v/linalg.norm(v)
    print i
    print v

    
pagerank(0.8,0.001)
    
    
