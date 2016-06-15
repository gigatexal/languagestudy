import random as rnd

unsorted_arr = [3,4,9,8,2,1,7]

def _mid(lst):
   arr_len = len(lst)
   if lst is not None and arr_len > 0:
      return int(arr_len/2)
   if arr_len == 1:
      return 1
   #else returns None      

def _split(lst):
   midp = _mid(lst)
   left,right = [],[]
   left,right = lst[0:midp],lst[midp:]
   return (left,right)

def _merge(left,right):
   combined = []
   for elem in left:
      combined.append(elem)
   for elem in right:
      combined.append(elem)
   return combined

def mrgSort(lst):
   srtd = []
   unsorted = lst;
   pivot = unsorted.pop(_mid(unsorted))
   left,right = _split(unsorted)
   return left,right,pivot,srtd


print (mrgSort(unsorted_arr) )
