numLines = 0
nums = []
with open('stocks.txt','r') as f:
   for i in f.readlines():
       numLines +=1
       nums.append(i.split(' '))

print (numLines)

print(nums)
