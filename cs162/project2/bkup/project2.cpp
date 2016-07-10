#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

struct Song {
   char title[CHAR_MAX];
   char artist[CHAR_MAX];
   char duration_minutes[CHAR_MAX];
   char duration_seconds[CHAR_MAX];
   char album[CHAR_MAX];
};

const char *FILENAME = "songs.txt";

template <class T> void get(T &var);
void get(char str[], const unsigned int size); 
unsigned int getNumLines(const char filename[]);
bool isValid(Song song);
bool get(Song songs[], const char filename[], unsigned int numLines);
bool writeOut(Song songs[], const char filename[], unsigned int numLines);

int main(){
   Song songs[1024];
   
   bool got = get(songs,FILENAME,getNumLines(FILENAME));
   if (got){
      cout << "got" << endl;
   }
   else {
      cout << "not got" << endl;
   }
   bool written = writeOut(songs,"OUTPUT.txt",getNumLines("songs.txt"));
   if (written){
      cout << "wrote" << endl;
   }
   else {
      cout << "not written" << endl;
   }
   return 0;
}

bool get(Song songs[], const char filename[], unsigned int numLines){
   bool loaded = false;
   ifstream in(filename);
   if (in){
       unsigned int i = 0;
       Song song;
       while (in.getline(song.title,CHAR_MAX,';')
              && in.getline(song.artist,CHAR_MAX,';')
              && in.getline(song.duration_minutes,CHAR_MAX,';')
              && in.getline(song.duration_seconds,CHAR_MAX,';')
              && in.getline(song.album,CHAR_MAX,'\n')
              && i < numLines){
          songs[i] = song;       
          i++; 
          loaded = true;
   } 
   }
   return loaded;
}
bool writeOut(Song songs[], const char filename[], unsigned int numLines){
   bool written = false;
   ofstream out(filename);
   if (out){
      for (int i = 0; i < numLines; i++){
         out << songs[i].title << ";"
             << songs[i].artist << ";"
             << songs[i].duration_minutes << ";"
             << songs[i].duration_seconds << ";"
             << songs[i].album << '\n';
      }
      written = true;
   } 
   else {
      written = false;
   }
   return written;
}
//ui
template <class T> void get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cout << "Data entered was invalid" << endl;
      cin.clear();
      cin.ignore(CHAR_MAX,'\n');
      cin >> val;
   }
   cin.ignore(CHAR_MAX,'\n');
   var = val;       
}
//ui
void get(char str[], unsigned int size){
   cin.get(str, size, '\n');
   while(!cin){
      cin.clear();
      cin.ignore(CHAR_MAX,'\n');
      cin.get(str, size, '\n');
   }
   cin.ignore(CHAR_MAX,'\n');
}
//make a private method to a wrapper class that opens a file and returns it's contents
unsigned int getNumLines(const char filename[]){
   ifstream in(filename);
   char line[CHAR_MAX];
   unsigned int numLines = 0;
   while(in.getline(line,CHAR_MAX)){
      ++numLines;
   }
   in.clear();
   in.seekg(0, ios::beg);
   in.close();
   return numLines;
}

bool isValid(Song song){
   bool valid = song.title 
       && song.artist 
       && song.duration_minutes 
       && song.duration_seconds 
       && song.album;

   return valid;
}

