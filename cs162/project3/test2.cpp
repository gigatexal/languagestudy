#include <iostream>
#include <cstring>
using namespace std;

template <class T> void get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cout << "Data entered was invalid" << endl;
      cin.clear();
      cin.ignore(128,'\n');
      cin >> val;
   }
   cin.ignore(128,'\n');
   var = val;
}

using namespace std;

int main(){


return 0;
}

