unsorted_arr = [3,4,9,8,2,1,7]

def _mid(lst):
   if lst is not None and len(lst) > 1:
      return int(len(lst)/2)
   if len(lst) == 1:
      return 1
   if lst is None or len(lst) < 1:
      return None #should throw an exception, handle it in the caller

def _split(lst,left,right):
   midp = mid(lst)
   for elem in lst[0:midp]:
      left.append(elem)
   for elem in lst[midp:]:
      right.append(elem)

def mrgsort(lst)#inplace sort
   right = []
   left = []
   pivot = _mid(lst)
   

