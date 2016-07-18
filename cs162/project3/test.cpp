#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Song.h"
using namespace std;

const int MAX_SONGS = 100;

//add to DB class
struct Loader {
   char title[128];
   char artist[128];
   char album[128];
   char length_minutes[128];
   char length_seconds[128];
};

int main(){

Song songs[MAX_SONGS];

fstream in("test.txt");

//put this into DB class
Loader l;

int i = 0;
while (      in.getline(l.title,Song::MAX_CHAR,';')
          && in.getline(l.artist,Song::MAX_CHAR,';')
          && in.getline(l.album,Song::MAX_CHAR,';')
          && in.getline(l.length_minutes,Song::MAX_CHAR,';')
          && in.getline(l.length_seconds,Song::MAX_CHAR,'\n')
          && i < 100){
             Song s(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             songs[i] = s;
             i++;         
      }

for (auto& s : songs){
    s.print();
}

return 0;
}

