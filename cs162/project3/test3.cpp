#include <iostream>
#include <cstring>
using namespace std;

class Person {
   public:
      Person();
      void set(char *name, int age);
   private:
      char name[128];
      int  age;
};

class Stor : public Person {
   public: 
      static const int MAX = 1024;
      Stor();
      void add(Person obj, unsigned int index);
      void remove(unsigned int index);
   private:
      Person data[MAX];
      unsigned int numElements;
};       
   

int main(){
   Stor s[1024];
   s.add( 

   return 0;
}


Stor::Stor() {
   this->numElements = 0;
}

void Stor::add(Person obj, unsigned int index) {
   this->data[numElements] = obj;
   this->numElements++;
}

void Stor::remove(unsigned int index){
   cout << "removed"<<endl;
   this->numElements--;   
}

Person::Person(){
   strncpy(this->name,"FirstName, LastName",sizeof(this->name));
   this->age = 50;
}

void Person::set(char *name, int age){
   strncpy(this->name,name,sizeof(this->name));
   this->age = age;
}
