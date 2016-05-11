/***************************************************
* Name: Alex Narayan
* Date: 5.10.2016
* Assignment: Lab 7
* Class: CS161
* Description: implement a function to raise a base
* to a power given two inputs base and power
* Resources: none
***************************************************/

#include <iostream>

using namespace std;

double pow(int base, int exponent);

void greeting();
void result(int base, int exponent);

int main() {
   int base, exponent;
   greeting();
   cin >> base >> exponent;
   result(base,exponent);
   
   system("pause");
   
   return 0;

}

void greeting(){
   std::cout << "Please enter two numbers: ";
}

void result(int base, int exponent){
   std::cout << "The result of " 
             << base 
             << " ^ " 
             << exponent 
             << " is "
             << pow(base,exponent) 
             << endl;
}

double pow(int base, int exponent){
//purposefully not using cmath.h for abs and pow functions
// edge cases
// base = 2, exponent = -2, answer = 1/2^2
// base = 2, exponent = 2, answer = 2^2
// base = 2, exponent = 0, answer = 1
// base = 0, exponent = 2, answer = 0
// base = 0, exponent = 0, answer = -1 or undefined
// limitation: infinite loop if user enters float for base or exponent
   int result = 1;
   if (exponent < 0){
      for (int i = exponent * -1; i > 0; i--){
         result *= base;         
      }
      return (1.0/(result));
   }
   if (exponent > 0) {
       for (int i = exponent; i > 0; i--){
         result *= base;
      }
      return result;
   }
   
   if (base == 0 || exponent == 0){
      if (base == 0){
         return 0;
      }
      else if (exponent == 0){
          return 1;
      }
   }

   
}






