#include <iostream>
using namespace std;
#include "list.h"

const int ARRAY_CAP = 100;
int main()
{
	int aList[ARRAY_CAP];
	int size = 0;
	print(aList, size);
	insert(10, aList, size);
	insert(10, aList, size);
	insert(4, aList, size);
	insert(40, aList, size);
	insert(25, aList, size);
        
	print(aList, size);

	for (int i = 0; i < size; i++){
           cout << aList[i] << endl;
        }
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
	return 0;
}


