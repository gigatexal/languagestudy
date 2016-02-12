'''
   simple program, if you could look back in time and buy a stock and sell it, what's the 
   max amount you could make?
   Input: a 1 x n array / list of stock prices where index position after index 0 denotes
          time after open, open being 9:30EST. 
   Output: Maximum profit. 
'''

stocks = [10, 7, 5, 8, 11, 9]


currLow = 99999999 #arbitrary to make the logic work, fixme?
currProfit = 0
for i in range(0,len(stocks)):
   if currLow > stocks[i]:
      currLow = stocks[i]

   potentialProfit = stocks[i] - currLow
   if (potentialProfit) > currProfit:
      currProfit = potentialProfit

print (currProfit)















