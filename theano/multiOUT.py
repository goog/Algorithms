import theano.tensor as T
from theano import function
a, b = T.dmatrices('a', 'b')
diff = a - b
abs_diff = abs(diff)
diff_squared = diff**2
f = function([a, b], [diff, abs_diff, diff_squared])
## return three varibles
print f([[1, 1], [1, 1]], [[0, 1], [2, 3]])
