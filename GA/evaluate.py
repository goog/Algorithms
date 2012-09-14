'''
Created on Jun 30, 2012

@author: googcheng
'''
import numpy as np
f = open('./ga.txt')

fitness= []
for line in f:
    line = line.strip()
    fitness.append(float(line))
   
fitness.sort()
print "the best fitness:",fitness[0]
print "the worst fitness:",fitness[499]
average = float(sum(fitness)) / len(fitness)
print "average:",average
print len(fitness)
for i in range(len(fitness)):


    #print np.abs(1-fitness[i])

    if fitness[i]>1.0:
        print "the position of value more than one:",i+1
        print "the proper is :", float(i)/len(fitness)
        break


   

f.close()
    


