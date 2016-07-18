#include "student.h"
#include <cstring>
//implement the required 3 functions here
/*
class Student
{
public:
        Student(const char initId[], double gpa);
        bool isLessThanByID(const Student& aStudent) const;
        bool isLessThanByGpa(const Student& aStudent) const;
        void print()const;
private:
        const static int MAX_CHAR = 100;
        char    id[MAX_CHAR];
        double  gpa;
};
*/
Student::Student(const char initId[], double gpa){
   strcpy(this->id,initId);
   this->gpa = gpa;
}

bool Student::isLessThanByID(const Student& aStudent) const {
   return this->id < aStudent.id;
}

bool Student::isLessThanByGpa(const Student& aStudent) const {
   return this->gpa < aStudent.gpa;
}

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}
