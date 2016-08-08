#include <iostream>
using namespace std;

struct Node {
   int data;
   Node *next;
   Node *prev;
};

class Doubly {
   private:
      Node *head;
      Node *tail;
      unsigned int size;
      void destroy(Node *& currHead);
      void add(Node *head, int data);
   public:
      Doubly();
      ~Doubly();
      void add(int data);
      const void print() const;
};

int main() {
   Doubly *d = new Doubly();
   d->add(1);
   d->print();
return 0;
}
Doubly::Doubly(){
   this->head = nullptr;
   this->tail = nullptr;
   this->size = 0;
}
Doubly::~Doubly(){
   destroy(head);
   destroy(tail);
}

void Doubly::destroy(Node *& currHead)
{
	if (currHead)
	{
		destroy(currHead->next);
		delete currHead;
	}
}

void Doubly::add(int data){
   add(this->head,data);
}
void Doubly::add(Node *head, int data){
   Node *entry = new Node;
   entry->data = data;

      entry->prev = this->head;
      this->head  = entry;
      entry->next = nullptr;

}
const void Doubly::print() const {
   if (this->head){
      cout << this->head->data << endl;
   }
}
