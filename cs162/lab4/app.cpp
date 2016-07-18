#include "student.h"

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	if(s1.isLessThanByID(s2))
	{
		cout << "about right!" << endl;
	}
	else
	{
		cout << "uhmm ..." << endl;
	}
	if(!s1.isLessThanByGpa(s2))
	{
		cout << "about right!" << endl;
	}
	else
	{
		cout << "uhmm ..." << endl;
	}
	return 0;
}
