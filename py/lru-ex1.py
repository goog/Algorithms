#!/usr/bin/python3.2


import functools
import urllib

@functools.lru_cache(maxsize=32)
def get_pep(num):
    '''Retrieve text of a Python Enhancement Proposal'''
    resource = 'http://www.python.org/dev/peps/pep-%04d/' % num
    try:
        with urllib.urlopen(resource) as s:
            return s.read()
    except:
        return 'Not Found'

for n in 8, 290, 308, 320, 8, 218, 320, 279, 289, 320, 9991:
    pep = get_pep(n)
    print(n, len(pep))

print(get_pep.cache_info())
