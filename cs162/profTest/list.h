//list.h
#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied
void duplicate(node * & new_copy); //provides a duplicate copy of the list

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
//

bool removeItem(node * curr, int target);
int numNodes(node * curr);
void printList(node* curr);
void printListBack(node* curr);
node deleteItem(node * curr, int target);
