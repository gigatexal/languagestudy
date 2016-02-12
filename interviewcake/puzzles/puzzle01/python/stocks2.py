import random
import math

MAX = 10001

min_price = 1
max_price = 500

stocks = [random.randint(min_price, max_price) for x in range(0,MAX)]

#stocks = [10, 7, 5, 8, 11, 9]

def profit(prices):
   currProfit = []
   for i in prices:
      currProfit.append(max(prices[prices.index(prices[i]):]) - prices[i])
   
   return max(currProfit)



