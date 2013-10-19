'''
Python supports a concept called "list comprehensions".
It can be used to construct lists in a very natural, easy way, like a mathematician is used to do.
'''

testList = [1,2,3,4]
def mul2(x):
  return x*2
print [mul2(i) for i in testList]

print 'some additional condition:'
print [mul2(i) for i in testList if i%2==0]


## loop from x ->y , y is the inner loop
print [x*y for x in [1,2,3] for y in  [1,2,3]]
