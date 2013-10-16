# works in py2.7


def outer():
    x = 1
    def inner():
        print(x) # 1
    return inner

foo = outer()
print(foo.func_closure) # d
foo()
