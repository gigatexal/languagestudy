def fizzbuzz(x):
    if (x % 15 ==0): #one computation here, instead of x % 5 == 0 and x % 3 == 0
        return 'fizzbuzz'
    if x % 3 == 0:
        return 'fizz'
    if x % 5 == 0:
        return 'buzz'
    else:
        return x

def run():
    f = [fizzbuzz(x) for x in range(1,101)] #use a lambda here?
    return f


def main():
    print(run())

main()
