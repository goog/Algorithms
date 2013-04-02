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

# do a tokenizer 

    
  
        if len(match):
            for m in match:
                #print 'match line before filter',m
                if (not filtone.search(m)) and (not filttwo.search(m)):
                    m=m.split("<div")[0]
                    m=m.split(ur'\u3010')[0]
                    #print 'match line after filter',m
                    mat=re.sub(ur'[\u3011\u3001\uff1a]{1}',' ',m,re.UNICODE)
                    synlist = mat.split(' ')
             
