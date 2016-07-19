#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DB.h"
using namespace std;

DB loadData(const char filename[]);


const int MAX_SONGS = 100;
const char songsFile[128] = "songs.txt";

struct Loader {
   char title[128];
   char artist[128];
   char album[128];
   char length_minutes[128];
   char length_seconds[128];
};

int main(){
   Song s;
   database = loadData(songsFile); 
   s = database.get(1);
   s.print(); 
   return 0;
}

DB loadData(const char filename[]){
   struct Loader {
      char title[128];
      char artist[128];
      char album[128];
      char length_minutes[128];
      char length_seconds[128];
   };
   DB db;
   Loader l;
   fstream in(filename);
   int i = 0;
   while (   in.getline(l.title,Song::MAX_CHAR,';')
          && in.getline(l.artist,Song::MAX_CHAR,';')
          && in.getline(l.length_minutes,Song::MAX_CHAR,';')
          && in.getline(l.length_seconds,Song::MAX_CHAR,';')
          && in.getline(l.album,Song::MAX_CHAR,'\n')
          && i < MAX_SONGS){
             Song s(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             db.add(s);
             i++;
      }
   return db; 
}
   
