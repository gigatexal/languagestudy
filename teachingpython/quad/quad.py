def greeting():
   print("Welcome, please follow the prompts and the program will spit out",
         "the roots to any quadratic equation in the form: ax^2+bx+c")

def get_coeffs():
   a = float(input("what is the 'a' coefficient, ax^2: "))
   b = float(input("what is the 'b' coefficient, ... +bx+ ...: "))
   c = float(input("what is the 'c' term or value ... +bx+c: "))
   return (a,b,c)

def compute_roots(inputs):
   #inputs should be a triple
   a,b,c = get_coeffs()
   x1 = (-b + ((b**2 - 4*a*c)**.5))/2*a
   x2 = (-b - ((b**2 - 4*a*c)**.5))/2*a
   return (x1,x2)


def main():
   greeting()
   print(compute_roots(get_coeffs))

main()

