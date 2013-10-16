def make_counter():
    count = 0
    def counter():
        nonlocal count
        count += 1
        return count
    return counter
    

mc = make_counter()
print(mc())
print(mc())
print(mc())
