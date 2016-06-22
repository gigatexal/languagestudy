#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cstring>
using namespace std;


int getInt();


int main(){

return 0;
}
int getInt(){
   int user_input;
   cin >> user_input;
   while(!cin){
      cin.clear();
      cin.ignore(CHAR_MAX, '\n');
      cin >> user_input;
   }
   cin.ignore(CHAR_MAX,'\n');
   return user_input;
}


















