/* compile via g++ -o proj1 project1.cpp */
#include <iostream>
#include <string>
using namespace std;

   /* singly linked list */
   struct Node {
      string item;
      float cost;
      int qty;
      Node *next;
   };

int main(){
   Node head;
   Node n;
   n.item = "TEST";
   n.cost = 999.99;
   n.qty = 2;
  
   head.next = &n;
   
   Node currNode;
   Node nextNode;
   currNode = *head.next;
   currNode.next = &nextNode;

   cout << currNode.item << endl;
   
   cout << (head.next++)->item << endl; 
   cout << (head.next->next++)->item << endl;
   return 0;
}
