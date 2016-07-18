#include "list.h"
#include <iostream>
using namespace std;

const int ARRAY_CAP = 100;

bool insert(int val, int intList[], int& size) {
   if (size == 0){
      intList[size] = val;
      size++;
      return true;
   }
   //find the index of where to add the value
   int i = 0;
   for (; i < size; i++){
       if (val < intList[i]){
           break;
       }
   }
   //add the value shifting over values where needed, does bounds checking
   int index = i;
   if (size + 1 < ARRAY_CAP){
       for (int i = index; i < size + 1; i++){
          intList[index+ 1] = intList[index];
       }
       intList[index] = val;
       size++;
   }
   return true;
}

bool remove(int val, int intList[], int& size) {
   bool success = false;
   int i;
   for (i = 0; i < size; i++){
      if (val == intList[i]){
         success = true;
         break;
      }
   //now that it's found, remove it by overwriting it
   for (int j = i; j < size-1 && success; j++){
      intList[j] = intList[j+1];
   }
      size--;
   }
   return success;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



