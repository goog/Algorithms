'''
Created on Jun 28, 2012

@author: googcheng
'''
def shekel(x,y):
        A = [-32., -16., 0., 16., 32.]
        a1 = A * 5
        a2 = reduce(lambda x1,x2: x1+x2, [[c] * 5 for c in A])
        r = 0.0
        for i in range(25):
            r += 1.0/ (1.0*(i+1) + pow(x-a1[i],6) + pow(y-a2[i],6))
        return 1.0/(0.002 + r)


#print shekel(-32,-32)