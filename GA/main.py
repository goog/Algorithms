'''
Created on Jun 26, 2012

@author: googcheng
'''
# -*- coding: utf-8 -*-
import numpy as np
import random
from shekel import shekel

class Genetic:
    def __init__(self):
        # Generation counter
        self.generation = 0
        # Chance of crossover (%/100)
        self.crossover_rate = 0.7
        # Chance of mutation (%/100)
        self.mutation_rate = 0.01
        # code length per individual
        self.L = 0
        # population size
        self.n = 0
        # Fitness value
        self.fitness_value = 0.0
        # chromosome data in numpy.ndarray
        self.chromosome = []
        # snapshots
        self.chromosome_snaps = []
        # save the outstanders
        self.outstanding = []
        # reserve one best and one worst  two individuals 
        self.reserve_values=[]
        self.index_commonest = 0

    def decode(self,numList):
        xl,yl= numList[:17],numList[17:]
        x,y= -65.536+0.001*int(''.join(map(str,xl)),2),-65.536+0.001*int(''.join(map(str,yl)),2)
        return x,y
    
    def generate_chromosome(self):
        self.chromosome= np.random.randint(2,size = self.n*self.L)

    def mutate(self):
        for i in range(self.n*self.L):
            if (random.random() <= self.mutation_rate):
                self.chromosome[i] = '1' if self.chromosome[i] == '0' else '0'
                                       
    def crossover(self):
        #cross_num: the number of individuals which will crossover
        cross_num=int(self.n*self.crossover_rate)
        if cross_num%2!=0:
            cross_num=cross_num-1
        arr = np.arange(self.n)
        np.random.shuffle(arr)
        cross_group=arr[:cross_num] 
        for i in range(cross_num/2):
            start=2*i
            man=self.chromosome[self.L*cross_group[start]:self.L*(cross_group[start]+1)]
            woman=self.chromosome[self.L*cross_group[start+1]:self.L*(cross_group[start+1]+1)]
            exchange_position= np.random.randint(self.L)
            man = man.tolist();woman = woman.tolist()
            man[exchange_position:],woman[exchange_position:]= woman[exchange_position:],man[exchange_position:]
            #  TODO  my crossover
            self.chromosome[self.L*cross_group[start]:self.L*(cross_group[start]+1)]=man
            self.chromosome[self.L*cross_group[start+1]:self.L*(cross_group[start+1]+1)]=woman

    def reserve_outstander_commonest(self):
        max,min,flag1,flag2 = 0.5,500.0,0,0
        for i in range(self.n):
            individual = self.chromosome[i*self.L:(i+1)*self.L]
            bid_list = self.decode(individual)
            result = self.fitness(bid_list[0], bid_list[1])
            if result < min:
                flag1 = i;min= result
            if result > max:
                flag2=i;max= result
        self.outstanding.append(self.chromosome[flag1*self.L:(flag1+1)*self.L])
        self.reserve_values.extend([self.chromosome[flag1*self.L:(flag1+1)*self.L],self.chromosome[flag2*self.L:(flag2+1)*self.L]])
        self.index_commonest= flag2*self.L
       
    # decide the architecture of a group       
    def select(self):
        #remove the commonest, now the group lack a individual,add a best
        self.chromosome= np.delete(self.chromosome, np.s_[self.index_commonest:self.index_commonest+self.L], axis=0)
        self.chromosome = np.append(self.chromosome,self.outstanding[-2])
             
    def newbee(self):
        #todo
        print 
                    
    def fitness(self,x1,x2):
        return shekel(x1,x2)


ga =Genetic()
ga.n = 20
ga.L = 2*17
ga.generation =100
ga.generate_chromosome()
ga.reserve_outstander_commonest()

for i in range(ga.generation):
    #print "###  generation NO. %s" % (i+1)
    ga.crossover()
    ga.mutate()
    ga.reserve_outstander_commonest()
    ga.select()

fp = open('./ga.txt', 'w')
np.savetxt('individuals.txt', ga.outstanding)
for i in ga.outstanding:
    list = ga.decode(i)
    fitness = ga.fitness(list[0], list[1])
    fp.write("it's fitness is :"+str(fitness)+'\n')
print "over!"
fp.close()
        
        
             
        
