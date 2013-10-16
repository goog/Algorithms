#!/usr/bin/python2.7

'''
Python supports a feature called function closures
which means that inner functions defined in non-global scope
remember what their enclosing namespaces looked like at definition time.
'''

def outer():
    x = 1
    def inner():
        print(x)
    return inner

foo = outer()
print(foo.func_closure)
foo()
