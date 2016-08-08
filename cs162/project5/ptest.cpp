#include <iostream>
using namespace std;

int main() {

   int *a = new int[10];
   *(a + 1) = 0;
   *(a + 2) = 12;

   cout << *(a + 1) << endl;
   cout << *(a+2) << endl;
return 0;
}
