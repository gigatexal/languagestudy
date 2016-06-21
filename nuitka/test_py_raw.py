import time

import random

def gen_random_int(start = 1,limit=100000):
   nums = (random.randint(start,limit) for x in range(limit))
   return nums


def sum_nums(gen_nums):
   total = 0
   for num in gen_nums:
      total += num

   return total



def main():
   curr_time = time.clock()
   nums = gen_random_int(1,1000000)
   total = sum_nums(nums)
   end_time = time.clock()
   print ("time taken: ", end_time - curr_time, " value was: ",total)



main()
