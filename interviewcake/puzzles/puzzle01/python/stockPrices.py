import random

stocks = (random.randint(1,20) for x in range(0,10000000))

with open('/home/gigatexal/code/interviewcake/puzzles/puzzle01/python/stocks.txt','w+') as stocks_txt:
   for i in stocks:
      stocks_txt.write(str(i + ' '))

