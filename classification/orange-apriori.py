import Orange

items = Orange.data.Table("item")

#play with support argument to filter out rules
rules = Orange.associate.AssociationRulesSparseInducer(items, support = 0.1) 
for r in rules:
    print "%5.3f %5.3f %s" % (r.support, r.confidence, r)

## get the frequent itemset

print "the frequent itemset is:"
ind = Orange.associate.AssociationRulesSparseInducer(support=0.4, storeExamples = True)
itemsets = ind.get_itemsets(items)
for itemset, tids in itemsets[:5]:
    print type(tids),tids   ## tids: transaction id list
    print "(%4.2f) %s" % (len(tids)/float(len(items))," ".join(items.domain[item].name for item in itemset))
