#include <iostream>
#include <cstring>
using namespace std;

//UI
/*
template <typename T>      
const T Person<T>::get(int index) const{
   return this->data[index];
   
};
*/

class Person {
   private:
      int age;
      int age2;
   
   public:
      Person();
      Person(int age, int age2);
      void print();
};

template <typename T> class Container {
   private:
      int index;
      T elems[100];
   public:
      Container();
      void add(T elem);
      T get(int index);
};

template<typename T> Container<T>::Container(){
   this->index = 0;
}

template<typename T> void Container<T>::add(T elem){
   this->elems[index] = elem;
   this->index++;
}

template<typename T> T Container<T>::get(int index){
   return this->elems[index];
}

Person::Person(){
;
}

void Person::print(){
   char str[128];
   strcpy(str,"test");
   cout << str << endl;
};


Person::Person(int age, int age2){
   this->age = age;
   this->age2 = age2;
};

int main(){

   Person p(29,31);
   Container<Person> db;
   db.add(p);
   db.get(0).print();

return 0;
}
   
