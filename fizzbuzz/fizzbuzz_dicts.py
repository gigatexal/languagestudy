fizbuzz = dict([(x,'fizzbuzz') for x in range(0,101,15)][1:])
fizz = dict([(x,'fizz') for x in range(0,101,3) if x % 5 != 0 or x not in fizbuzz.keys()][1:])
buzz = dict([(x,'buzz') for x in range(0,101,5) if x not in fizbuzz.keys()][1:])
others = dict([(x,x) for x in range(1,101) if x not in fizbuzz.keys() and x not in fizz.keys() and x not in buzz.keys()])


def merge_dicts(*dict_args):
   result = {}
   for dictionary in dict_args:
      result.update(dictionary)
   return result

fzbz = merge_dicts(fizbuzz,fizz,buzz,others)


def testMe():
   for key,value in fzbz:
      print(key,value,)



testMe()


