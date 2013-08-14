import theano.tensor as T
from theano import function
from theano import Param

x, y = T.dscalars('x', 'y')
z = x + y
f = function([x, Param(y, default=1)], z)
print f(33)
#array(34.0)
print f(33, 2)
