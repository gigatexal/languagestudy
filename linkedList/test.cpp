#include <iostream>
using namespace std;

struct Node {
   int data;
   Node *next;
};


int main() {
   Node *head = new Node;
   Node *d = new Node;
   d->data = 1;
   d->next = nullptr;
   head->next = d;
   Node *dd = new Node;
   dd->data = 2;
   dd->next = nullptr;
   
   d->next = dd;
   Node *ddd = new Node;
   ddd->data = 3;
   ddd->next = nullptr;
   dd->next = ddd;  

 
   Node *iter = new Node;
   iter = head->next;
   cout << iter << endl;
   while(iter){
      cout << iter << endl;
      cout << iter->data << endl;
      iter = iter->next;
   }   
      
   delete iter;
   delete d;
   delete dd;
   delete ddd;
   delete head;

return 0;
}

