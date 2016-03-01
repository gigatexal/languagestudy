"""
given a list_of_ints, find the highest_product you can get from three of the integers
the input list will always have at least 3 integers
"""

def highest_product(list_of_ints):
   """
   return the inputs and max product as a tuple ((x,y,z),x*y*z) given a list with len of >= 3
   """
   from itertools import combinations
   from operator import itemgetter
   
   lst = sorted(list_of_ints) #ensure the list is sorted
                     #would be nice if I could garuntee a sorted list

   lst_tuples = {((x, y, z), x * y * z) for (x, y, z) in combinations(lst[-3::] + lst[:3:], 3) }

   return max(lst_tuples,key=itemgetter(1))




import random

lst = [random.randint(-1000,1000) for x in range(1,1001)]
print(highest_product(lst))





