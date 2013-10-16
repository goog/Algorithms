#!/usr/bin/python

a = (1,2)
b = (3,4)
# concat two tuples
print(a+b)

c = [3,4]


print a + tuple(c)
print list(a) + c

c.extend(a)
print c

# tuple has only two methods.

print "tuple count function:",a.count(1)
print "tuple index function:",a.index(1)


