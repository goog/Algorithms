'''
Created on Jun 30, 2012

@author: googcheng
'''
'''
Created on Jun 29, 2012

@author: googcheng
'''
# -*- coding: utf-8 -*-
import numpy as np
import random
from f1 import f1

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
            fitness_list_prior = [self.fitness(man),self.fitness(woman)]
            fitness_list_prior.sort()
            exchange_position= np.random.randint(self.L)
            man = man.tolist();woman = woman.tolist()
            man[exchange_position:],woman[exchange_position:]= woman[exchange_position:],man[exchange_position:]
            # if crossovered individuals not improved , drop them.
            fitness_list = [self.fitness(man),self.fitness(woman)]
            fitness_list.sort()
            # prior smaller is bigger than these bigger one
            if fitness_list_prior[0]>fitness_list[1]:
                continue
            self.chromosome[self.L*cross_group[start]:self.L*(cross_group[start]+1)]=man
            self.chromosome[self.L*cross_group[start+1]:self.L*(cross_group[start+1]+1)]=woman

    def reserve_outstander_commonest(self):
        max,min,flag1,flag2 = 0.0,100.0,0,0
        for i in range(self.n):
            individual = self.chromosome[i*self.L:(i+1)*self.L]
            result = self.fitness(individual)
            if result < min:
                flag1 = i;min= result
            if result > max:
                flag2=i;max= result
        self.outstanding.append(self.chromosome[flag2*self.L:(flag2+1)*self.L])
        self.reserve_values.extend([self.chromosome[flag2*self.L:(flag2+1)*self.L],self.chromosome[flag1*self.L:(flag1+1)*self.L]])
        self.index_commonest= flag1*self.L
        
    def newbee(self):
        if self.isLocal():
            if self.chromosome_snaps is not None:
                self.chromosome = self.chromosome_snaps[-1]
            else: 
                self.generate_chromosome()
        elif len(self.outstanding)>2 and self.fitness(self.outstanding[-1])>self.fitness(self.outstanding[-2]) and self.fitness(self.outstanding[-1])>self.fitness(self.outstanding[-3]):
            self.chromosome_snaps.append(self.chromosome)
            
    def isLocal(self):
        # from the type of gene(as the origin of );  
        list = []
        for i in range(self.n):
            list.append(str(self.chromosome[i*self.L:(i+1)*self.L]))
        sorted = {}.fromkeys(list).keys()
        if len(sorted) < 3: 
            print "danger!"   
            return True
       
    # decide the architecture of a group       
    def select(self):
        self.chromosome= np.delete(self.chromosome, np.s_[self.index_commonest:self.index_commonest+self.L], axis=0)
        self.chromosome = np.append(self.chromosome,self.outstanding[-2])
                               
    def fitness(self,numList):
        xl,yl,zl= numList[:10],numList[10:20],numList[20:30]
        x1,x2,x3= -5.12+0.01*int(''.join(map(str,xl)),2),-5.12+0.01*int(''.join(map(str,yl)),2),-5.12+0.01*int(''.join(map(str,zl)),2)
        return f1(x1,x2,x3)


ga =Genetic()
ga.n = 20
ga.L = 3*10
ga.generation =100
ga.generate_chromosome()
ga.reserve_outstander_commonest()

for i in range(ga.generation):
    #print "###  generation NO. %s" % (i+1)
    ga.crossover()
    ga.mutate()
    ga.newbee()
    ga.reserve_outstander_commonest()
    ga.select()

fp = open('./ga_f1.txt', 'a')
#np.savetxt('individuals.txt', ga.outstanding,fmt="%i")
fitness_list= []
for i in ga.outstanding:
    fitness_list.append(ga.fitness(i))
fitness_list.sort()
fp.write(str(fitness_list[0])+'\n')
print "over!"
fp.close()
                
             
        
