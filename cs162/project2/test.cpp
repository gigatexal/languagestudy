#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <climits>
using namespace std;

struct Data {
   char name[CHAR_MAX];
   char duration[CHAR_MAX];
   char duration2[CHAR_MAX];
};

unsigned int getNumLines(const char filename[]){
   ifstream in(filename);
   char line[CHAR_MAX];
   unsigned int numLines = 0;
   while( in.getline(line,CHAR_MAX) ){
      ++numLines;
   }
   return numLines;
}
    
int main(){
  ifstream infile  ("songs.txt");
  int fileLen = getNumLines("songs.txt");
  cout << fileLen << endl;
  Data d;
  
  Data songs[128];

  int i = 0;
  while(infile.getline(d.name,CHAR_MAX,';') &&
        infile.getline(d.duration,CHAR_MAX,';') &&
        infile.getline(d.duration,CHAR_MAX) && i < fileLen){
     
     songs[i] = d;
     i++;
  }
  
  for (int i = 0; i < fileLen; i++){
     cout << songs[i].name << " : " << songs[i].duration << " : " << songs[i].duration2 << endl;
  }   
   
  infile.close();
  return 0;
}

   
   
