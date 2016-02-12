fizbuzz = dict([(x,'fizzbuzz') for x in range(0,101,15)][1:])
fizz = dict([(x,'fizz') for x in range(0,101,3) if x % 5 != 0][1:])
buzz = dict([(x,'buzz') for x in range(0,101,5) if x not in fizz][1:])
others = [x for x in range(0,101) if x not in fizbuzz and x not in fizz and x not in buzz]

def fbuzz():
   for i in range(1,101):
       if i in fizbuzz.keys():
          print(fizbuzz.pop(i))
       if i in fizz.keys():
           print(fizz.pop(i))
       if i in buzz.keys():
           print(buzz.pop(i))
       if i in others:
           print(i)


print(fbuzz())
import dis

print(dis.dis(fbuzz))

