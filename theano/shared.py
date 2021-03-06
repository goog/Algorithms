import theano.tensor as T
from theano import function
from theano import Param

from theano import shared
state = shared(0)
inc = T.iscalar('inc')
accumulator = function([inc], state, updates=[(state, state+inc)])


print state.get_value()
# 0
print accumulator(1)
#array(0)
print state.get_value()
#array(1)
print accumulator(300)
#array(1)
print state.get_value()
#array(301)


state.set_value(-1)
print accumulator(3)
#array(-1)
print state.get_value()
#array(2)
