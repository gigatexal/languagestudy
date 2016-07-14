#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Song.h"
using namespace std;

struct Loader {
   char title[128];
   char artist[128];
   char album[128];
   int length_minutes;
   int length_seconds;
}

int main(){

Song songs[100];

fstream in("test.txt");

Loader l;

while (in && s.getArtist(getline(in,l.title,sizeof(Song::MAX_SIZE)))
          &&
   

return 0;
}
