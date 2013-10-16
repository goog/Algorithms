#!/usr/bin/python

def a(*x):
    if len(x)==0:
        print 'None'
    else:
        print x

print("  ")
a(1,2,3,"str")


def ab(**x):
    if len(x)==0:
        print 'None'
    else:
        print x  

## return a dictionary
ab(x=1,y=2)
