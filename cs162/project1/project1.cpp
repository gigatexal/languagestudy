/* compile via g++ -o proj1 project1.cpp */
#include <iostream>
#include <string>
using namespace std;

/* singly linked list */
struct Node {
   string _item;
   float _cost;
   int _qty;
   Node *_next;
};

class simpleLinkedList {
   private:
      Node _head;
      Node _tail;
      int _size;
   public:
      simpleLinkedList();
      ~simpleLinkedList();
      void add_back(Node n);
      int size();
      void get_first();
};

int main(){
   simpleLinkedList *list = new simpleLinkedList();
   cout << list->size() << endl;


   return 0;
}

simpleLinkedList::simpleLinkedList(){
   _head._next = &_tail;
   _tail._next = 0; //null, empty, end here
   _size = 0;
};

simpleLinkedList::~simpleLinkedList(){
   //TODO: add destructor stuff;
};

void simpleLinkedList::add_back(Node n){
   //TODO: finish me   
   _size++;
}

int simpleLinkedList::size(){
   return _size;
};


