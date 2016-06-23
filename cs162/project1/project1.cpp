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
void greeting();
double total(Item items[]);
double subtotal(Item item);
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

double subtotal(Item item){
   return item.qty * item.price;
}

double total(Item items[]){
   int index = 0;
   double totalCost;
   while (items[index].name && items[index].qty && items[index].price){
       totalCost += subtotal(items[index]);
       index++;
   }
   return totalCost;
}

void greeting(){
   cout << "Going shopping? Wouldn't it be nice to know the current"
        << " value of the things in your basket?" << endl;

   cout << "Follow the prompts and the program will keep track of your spending." << endl;
   return;
}

void UI(){
   const int MAX_CART_SIZE = 1024;
   char quit = 'y';
   Item items[MAX_CART_SIZE];
   unsigned int index = 0;
 
   greeting();
 
   while ( (quit != 'n' || quit != 'N') && index < MAX_CART_SIZE){
      Item currItem;
      
      cout << "Enter in the name of the item e.g Cracker Jacks: ";
      get(currItem.name,CHAR_MAX);
      cout << "Enter in the price of " << currItem.name << " in dollars and cents e.g 12.98: ";
      get(currItem.price);
      cout << "Enter in the quantity of " << currItem.name << "(s) in whole numbers: ";
      get(currItem.qty);
      //add the item to the array of items
      items[index] = currItem;      
      
      //display running total
      cout.setf(ios::fixed, ios::floatfield);
      cout.setf(ios::showpoint);
      cout.precision(2);
      for (int i = 0; i < MAX_CART_SIZE; i++){
         if (items[i].name && items[i].qty && items[i].price){
            cout << setw(20) << right << setw(6) << i << ": " << right << setw(20) << items[i].name << right << setw(10) << " " << items[i].price << right << setw(10) << " " << items[i].qty << right << setw(10) << " subtotal " << subtotal(items[i]) << endl;
          }
         else {
         break;
         }
      }
      cout << "Current total of your basket: $" << total(items) << endl;  

      cout << "Would you like to quit? y - yes to quit, n - no to continue shopping ";
      get(quit);
      if (quit == 'y' || quit == 'Y'){
         break;
      }
      index++;
      
   }
   return;   
}


