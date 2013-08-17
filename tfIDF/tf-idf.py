'''
Created on May 21, 2012

@author: googcheng
'''
#!/usr/bin/python
# -*- coding: utf-8 -*-

import urllib
import re

filtone= re.compile(ur'href=#\d+')
filttwo= re.compile(ur'</script>')
chs=re.compile(ur'[\u4e00-\u9fa5]+')
pattern=re.compile(ur'href=/view/.*</a>$')

##todo
