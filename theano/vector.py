import theano
a = theano.tensor.vector() # declare variable
out = a + a ** 10               # build symbolic expression
f = theano.function([a], out)   # compile function
print f([0, 1, 2])  # prints `array([0, 2, 1026])`


## a ** 2 + b ** 2 + 2 * a * b.
a = theano.tensor.vector() # declare variable
b = theano.tensor.vector() 
out = a ** 2 + b ** 2 + 2 * a * b               # build symbolic expression
f = theano.function([a,b], out)   # compile function
print f([0, 1, 2],[3,4,5])  # prints `array([0, 2, 1026])`






