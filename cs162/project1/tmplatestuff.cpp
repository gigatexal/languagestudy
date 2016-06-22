#include <iostream>
#include <climits>
using namespace std;
//TODO: template a function to get an array of ints or chars etc
template <class T> void get(T &var);
void get(char cstr[], const int cstrSize);

int main(){
   int g;
   get(g);
   cout << g << endl;
   char c;
   get(c);
   cout << c << endl;
return 0;
}

template <class T> void get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cin.clear();
      cin.ignore(CHAR_MAX,'\n');
      cin >> val;
   }
   cin.ignore(CHAR_MAX,'\n');
   var = val;       
}

