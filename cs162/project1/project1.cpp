#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void display_output(float money);

int main(){
   string item;
   char user_input;
   float cost;
   while (true){
     cout << "Enter in the item: ";
     getline(cin,item);
     cout << "Enter in the price: ";
     cin >> cost;
     cout << "continue ? y - to continue, n - to exit: " << endl;
     cin  >> user_input;
     if (user_input == 'n' || user_input == 'N'){
        break;
     }
   }

   return 0;
}

void display_output(float money){
   //fix it so that it doesn't round up
   cout.setf(ios::fixed, ios::floatfield);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << money << endl;
}
