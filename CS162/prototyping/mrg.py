import random as rnd

unsorted_arr = [3,4,9,8,2,1,7]

def _mid(lst):
   return int(len(lst)/2)

r = []
print(_mid(r))
for i in range(50):
   arr = [x for x in range(0,int(rnd.random()*10)+1)]
   print(len(arr))
   print("midpoint is ",_mid(arr))


