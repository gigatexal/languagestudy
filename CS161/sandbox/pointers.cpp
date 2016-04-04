/*****************
 * name: Alex N
 * purpose: template
 * date: 4/3/2016
 * etc
 * ****************/

#include <iostream>
#include <string>

int main() {
   int *p; 
   int q;
   
   q = 10;
   p = &q;
   std::cout << q << std::endl;
   std::cout << &p << std::endl;
   *p = (*p)++; 
   std::cout << q << std::endl;
   std::cout << &p << std::endl;	


   return 0;
}

