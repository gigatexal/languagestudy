import random

#stocks = [10, 7, 5, 8, 11, 9]
stocks = [random.randint(1,20) for x in range(0,100000001)]


currLow = 99999999
currProfit = 0
for i in range(0,len(stocks)):
   if currLow > stocks[i]:
      currLow = stocks[i]

   potentialProfit = stocks[i] - currLow
   if (potentialProfit) > currProfit:
      currProfit = potentialProfit

print (currProfit)















