#!python
# -*- coding: utf-8 -*-
import re

print "case one:"
p = re.compile(r'(?<=abc)def')
print p.search('abcdef').group()

print "case two:"
s = u'我好'
print type(s)
msg = u'你好，我好，大家好'
match = re.findall(s, msg)
print match[0]



print "match vs search"
p1 = re.compile(r'a')
p2 = re.compile(r'b')
mat = p1.match("abcdef")
if mat:
    print mat.group()
print "match the 'b' at the begin of string"
print p2.match("abcdef")
print p1.search('abcdef')

''' " If capturing parentheses are used in pattern,
then the text of all groups in the pattern are also returned as part of the resulting list." '''
print re.split('\W+', 'test, test, test.')
print re.split('(\W+)', 'test, test, test.') 
