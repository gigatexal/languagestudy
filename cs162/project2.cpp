#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
using namespace std;

struct Item {
   char title[CHAR_MAX];
   char artist[CHAR_MAX]
   unsigned int  duration_minutes;
   unsigned int  duration_seconds;
   char album[CHAR_MAX];
};

template <class T> void get(T &var);
void get(char str[], const unsigned int size); 
void readFile(ifstream& file, dest[CHAR_MAX]);
void writeFile(ofstream& file, input[CHAR_MAX]);

int main(){
    

  return 0;
}

template <class T> void get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cout << "Data entered was invalid" << endl;
      cin.clear();
      cin.ignore(CHAR_MAX,'\n');
      cin >> val;
   }
   cin.ignore(CHAR_MAX,'\n');
   var = val;       
}

void get(char str[], unsigned int size){
   cin.get(str, size, '\n');
   while(!cin){
      cin.clear();
      cin.ignore(CHAR_MAX,'\n');
      cin.get(str, size, '\n');
   }
   cin.ignore(CHAR_MAX,'\n');
}


