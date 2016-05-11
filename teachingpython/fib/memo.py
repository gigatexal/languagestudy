def memo(func):
   cache = {}
   def helper(*args):
      if args in cache:
         return cache[args]
      else:
         cache[args] = func(*args)
         return cache[args]
   return helper


@memo
def fib(n):
   return n if n < 2 else fib(n-2) + fib(n-1)


print (fib(500))
