#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Data {
   char name[256];
   int duration;
   int duration2;
};

int main(){
  ifstream infile  ("songs.txt");
  
  Data d;
  
  infile.getline(d.name, 256,';');
  infile >> d.duration;
  //infile.ignore(';');
  infile >> d.duration2;

  cout << d.name << " " << d.duration << d.duration2 << endl;  

  infile.close();
  return 0;
}

   
   
