#!/usr/bin/python



d={1:'one',2:'two'}
print d
d=['one','two']
print d

##How to check whether d is dict or list?
##You can either use type() or .__class__


print type(d)
print d.__class__

d={}
if type(d).__name__=='dict':
     print 'Its dict!'
else:
     print 'Its not dict'


d={}
if type(d)==type(dict()):
     print 'Its dict!'
else:
     print 'Its not dict'

## identify the type of class
class myclass():
     pass

c=myclass()

if c.__class__.__name__==myclass.__name__:
      print 'c is an instant of myclass'
else:
      print 'c is something else'

## method 2:
if type(c).__name__=='instance':
     if c.__class__.__name__=='myclass':
             print 'its from myclass'
