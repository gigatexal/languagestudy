#include <iostream>
using namespace std;

class Animal {
   public:
      Animal();
      char *s;
      bool get() const;
      void set(bool val);
      int getW();
   private:
      bool _hasFur;  
      int  wasSet;
};

class Human : public Animal {
   public:
      Human();
};

int main(){
  
   Animal monkey;
   cout << monkey.get() << endl;
   Human man;
   cout << man.get() << endl;
   cout << man.s << endl;    
   man.set(false);
   cout << man.getW() << endl;
   cout << man.get() << endl;
return 0;
}

Animal::Animal(){
   _hasFur = true;
   wasSet = 99;
   s = "ANIMAL";
}
int Animal::getW(){
   return wasSet;
}

bool Animal::get() const {
   return _hasFur;
}

void Animal::set(bool val){
   _hasFur = val;
}

Human::Human(){
   bool f = false;
   this->set(f); 
}


