#!/usr/bin/python
import itertools
def spam():
    yield"first"
    yield"second"
    yield"third"


for x in spam():
    print x


gen=spam()
print gen.next()
print gen.next()
print gen.next()


def imerge(a, b):
    for i, j in itertools.izip(a,b):
        yield i
        yield j

def chain(*iterables):
    # chain('ABC', 'DEF') --> A B C D E F
    for it in iterables:
        for element in it:
            yield element



if __name__ =="__main__":
    a = [1,2]
    b = [5,6,7,8]
    gen = imerge(a,b)
    li = list(gen)
    print li

    merge =  itertools.chain(a,b)
    for i in merge:
        print i
