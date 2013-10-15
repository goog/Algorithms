#!/usr/bin/python

# yy test on 10.14

li = []
def df(a):
    for i in a:
	if type(i) is int:
	    li.append(i)
        else:
	    df(i)
    return li
	
if __name__=="__main__":
    a =(1,2,3,(4,5,6))
    print df(a)
	
