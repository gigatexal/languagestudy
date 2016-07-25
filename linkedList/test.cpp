#include <iostream>
using namespace std;

struct Node {
   Node *next;
   int value;
};

class List {
   public:
      List();
      void add(int val);
      //List get();
   private:
      Node *head;
      int size = 0;
};


int main(){



return 0;
}

List::List(){
   this->head = nullptr;
}

void List::add(int val){
   if (this->size == 0){
      Node *next;
      this->head = next;
      this->head.value = val;
   }
   else {
      this->head = this->head.next;
      this->      
}

