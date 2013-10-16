#!/usr/bin/python2.7

class Coordinate(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __repr__(self):
        return "Coord: " + str(self.__dict__)



def sub(a, b):
    return Coordinate(a.x - b.x, a.y - b.y)


def wrap(func):
    def inter(*args):
        if (len(args) == 2):
            return func(args[0],args[1])
        else:
            print "args length doesn't equal two "
            return None
    return inter

@wrap
def add(a, b):
    return Coordinate(a.x + b.x, a.y + b.y)
a = Coordinate(1,2)
b = Coordinate(3,4)
print add(a,b)
print add(a,b,b)


