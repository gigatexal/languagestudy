#include <iostream>
#include <fstream>

using namespace std;

class DB {
   private:
      int *elements;
      int size;
 
   public:
     DB();
     ~DB(); 
     int getNumLines();
     int getSize() const;
};

int main(){
   DB *d = new DB();
   d->getNumLines();
   cout << d->getSize() << endl;
   delete d;
   return 0;
}


DB::DB(){
  int size = this->getNumLines();
  delete this->elements;
  this->elements = new int[size + 1];
}

int DB::getSize() const {
   return this->size;
};

DB::~DB(){
   delete [] elements;
}

int DB::getNumLines(){
   ifstream f("songs.txt");
   int i = 0;
   char dummyLine[5];
   while (f.getline(dummyLine,5)){
      ++i;
   }
   
   this->size = i + 1;
   f.close();
  }
