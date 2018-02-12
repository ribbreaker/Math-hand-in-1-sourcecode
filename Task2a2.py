# -*- coding: utf-8 -*-
"""
Created on Tue Jan 30 18:22:08 2018

@author: Ribbreaker
"""

import itertools as it
import numpy as np

sampled = list (it.product(range(6),repeat = 5)) #sample of all possible combinations of rolls

eventd = list (it.permutations(range(6),5)) # the valid/relevant roll(s)
             
"""
print (sampled)
print (len(eventd), "/", len(sampled))
 """





samplec = list (it.combinations(range(52),5))  #sample of all combinations of cards

eventc = list(it.combinations(range (13),5))  
"""
print(eventc)
print(len(eventc), '/', len(samplec))
"""


sampleq = list (it.permutations(range(6),6)) #samples all the possible combinations of the people

eventq = list (it.combinations(range(6),6)) #chance of a single combination happening (this is 1 obviously)
"""
print(sampleq)
print(len(eventq), "/", len(sampleq))

"""


"""
***************************************************
These use maps and filters
"""

print(list (map(lambda d: len(eventd)/len(sampled),eventd)))

print(list (map(lambda c: len(eventc)/len(samplec),(eventc))))

print(list (map(lambda q: len(eventq)/len(sampleq),(eventq))))

