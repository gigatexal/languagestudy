#include <iostream>
using namespace std;

int toInt(char input);
bool isVowel(char c);

int main(){
   char a = 'a';
   cout << toInt(a);
   

return 0;
}

int toInt(char input){
   return static_cast<int>(input);
}


