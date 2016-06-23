#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
using namespace std;

struct Item {
   char name[CHAR_MAX];
   unsigned int qty;
   double price;
};

template <class T> void get(T &var);
void get(char str[], const unsigned int size); 
void UI();
double total(Item items[]);

int main(){
  UI();  

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

void UI(){
   const int MAX_CART_SIZE = 1024;
   double total = 0;
   char quit = 'y';
   Item items[MAX_CART_SIZE];
   unsigned int index = 0;
  
   cout << "Going shopping? Wouldn't it be nice to know the current"
        << " value of the things in your basket?" << endl;
   
   cout << "Follow the prompts and the program will keep track of your spending." << endl;
 
   while ( (quit != 'n' || quit != 'N') && index < MAX_CART_SIZE){
      Item currItem;
      
      cout << "Enter in the name of the item e.g Cracker Jacks: ";
      get(currItem.name,CHAR_MAX);
      cout << "Enter in the price of " << currItem.name << " in dollars and cents e.g 12.98: ";
      get(currItem.price);
      cout << "Enter in the quantity of " << currItem.name << "(s) in whole numbers: ";
      get(currItem.qty);


      items[index] = currItem;      
      cout << "Would you like to quit? ";
      get(quit);
      if (quit == 'y' || quit == 'Y'){
         break;
      }
      index++;
      
   }
   //display the totals
   for (int i = 0; i < MAX_CART_SIZE; i++){
      if (items[i].name && items[i].qty && items[i].price){
         cout << setw(20) << i << ": " << items[i].name << " " << items[i].price << " " << items[i].qty << " subtotal " << items[i].qty * items[i].price << endl;   
      }
      else {
         break;
      }
   }
   
}


