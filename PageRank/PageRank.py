from numpy import *
import sys
import ast
# Parameter M adjacency matrix where M_i,j represents the link from 'j' to 'i', such that for all 'j' sum(i, M_i,j) = 1
# Parameter d damping factor
# Parameter v_quadratic_error quadratic error for v
# Return v, a vector of ranks such that v_i is the i-th rank from [0, 1]

def pagerank(d,v_quadratic_error):
    eg= '''[[0,0,0,0,1],
          [0.5,0,0,0,0],
          [0.5,0,0,0,0],
          [0,1,0.5,0,0],
          [0,0,0.5,1,0]]'''
    print "input a matrix like:\n",eg
    M = raw_input('input matrix:\n')
    while(not M):
        M = raw_input('no input! please input OR press exit to quit \n')
    if M=='exit':
        sys.exit()
    M = array(ast.literal_eval(M))    
    N=M.shape[1]
    v=random.rand(N,1)
    # norm:sqrt(dot(v,v)) to regularization
    v=v/linalg.norm(v)
    a=array([[inf]]);last_v = dot(ones((N,1)),a)
    # here d is smooth parameter
    M_hat=(d * M)+(((1-d)/N)*ones((N,N)))
    i=0
    while(linalg.norm(v - last_v) > v_quadratic_error):
        i+=1
        last_v = v
        v = dot(M_hat,v)
        v = v/linalg.norm(v)
    print "after %s iters,it converges" %i
    print "The PageRank is:\n",v

pagerank(0.85,0.001) 
