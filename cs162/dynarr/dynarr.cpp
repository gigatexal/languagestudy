#include <iostream>
#include <cstring>
using namespace std;

template<class T> void get(T &var){
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

void get(char str[], unsigned int size){
   cin.get(str, size, '\n');
   while(!cin){
      cout << "Field cannnot be empty. Please enter in something." << endl;
      cin.clear();
      cin.ignore(128,'\n');
      cin.get(str, size, '\n');
   }
   cin.ignore(128,'\n');
}

char id = new char[128];

void getb(const char name[]){
   delete[] id;
   id = new char[strlen(name)+1];
   strcpy(id,name);
}

int main(){
    get(id,1024); 
    getb(id);
    cout << id << endl;   


    return 0;
}
