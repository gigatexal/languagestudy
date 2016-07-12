#include <iostream>
using namespace std;
#include "list.h"

const int ARRAY_CAP = 100;
int main()
{
	int aList[ARRAY_CAP];
	int size = 0;
        insert(4,aList,size);
        insert(5,aList,size); 
/*
	print(aList, size);
	insert(10, aList, size);
	insert(10, aList, size);
	insert(4, aList, size);
	insert(40, aList, size);
	insert(25, aList, size);
	print(aList, size);
	if(!remove(5, aList, size))
	{
		cout << "the list doesn't have 5" << endl;
	}
	if(!remove(10, aList, size))
	{
		cout << "the list doesn't have 10" << endl;
	}
	if(!remove(40, aList, size))
	{
		cout << "the list doesn't have 40" << endl;
	}
	if(!remove(4, aList, size))
	{
		cout << "the list doesn't have 4" << endl;
	}
	print(aList, size);
*/
	return 0;
}


bool insert(int val, int intList[], int& size) {
   //find index to add this to
   if (size == 0){
      intList[size] = val;
      size++;
      return true; 
   }
   int index = 0;
   for (; index < size; index++){
       if (val < intList[index]){
           break;
       }
      cout << index << endl;
   }
}

bool remove(int val, int intList[], int& size) {


}

void print(const int intList[], int size) {


}

