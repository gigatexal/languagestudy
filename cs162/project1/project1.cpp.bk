#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void display_output(float money);
string get_item();
float get_cost(string item);
float get_cost();
void clear_input_buffer();

int main(){
   
   char user_input;
   float cost;
   float running_total;

   while (true){
     item = get_item();
     cout << "Item entered: " << item << endl;
     cost = get_cost(item);
     cout << "Cost entered: " << cost << endl;
     cout << "Do you want to continue? type y - to continue, n - to exit: ";
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

void clear_input_buffer(){
   cin.clear();
   cin.ignore(CHAR_MAX,'\n');
}

string get_item(){
   string input;
   cout << "Enter in the item name e.g Apples: ";
   getline(cin,input);
   return input;
}

float get_cost(string item){
   float cost;
   cout << "Enter in the price of :";
   cin >> cost;
   while(!cin){
      get_cost();
   return cost;
}
