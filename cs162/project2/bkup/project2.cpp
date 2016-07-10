#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Song {
   char title[CHAR_MAX];
   char artist[CHAR_MAX];
   char duration_minutes[CHAR_MAX];
   char duration_seconds[CHAR_MAX];
   char album[CHAR_MAX];
};

const char *FILENAME = "songs.txt";
const int MAXSONGS = 1024;

template <class T> void get(T &var);
void get(char str[], const unsigned int size); 
unsigned int getNumLines(const char filename[]);
bool isValid(Song song);
bool get(Song songs[], const char filename[], unsigned int numLines);
bool writeOut(Song songs[], const char filename[], unsigned int numLines);




int main(){
   Song songs[MAXSONGS];
   get(songs,FILENAME,getNumLines(FILENAME));
   int numSongs = 0;
   for (auto s: songs){
      if (isValid(s)){
         numSongs++;
       }
   }
   cout << numSongs << endl;  
   //begin UI
   char input = 'n';
   while (input != 'q'){
   cout << setw(60) << setfill('_') << left << "Enter in a new song's info " << right << "(n)" << endl;
   cout << setw(60) << setfill('_') << left << "Display currently loaded songs from the DB " << right << "(d)" << endl;
   cout << setw(60) << setfill('_') << left << "Remove a song by a given index " << right << "(r)" << endl;
   cout << setw(60) << setfill('_') << left << "Search for songs by artist " << right << "(a)" << endl;
   cout << setw(60) << setfill('_') << left << "Search for songs by album " << right << "(b)" << endl;
   cout << setw(60) << setfill('_') << left << "Quit the program " << right << "(q)" << endl;
   cout << "Enter in your selection here: ";
   get(input);
   switch (input){
      case 'n': 
         cout << "new song" << endl;
         break;
      case 'd':
         cout << "display" << endl;
         break;
      case 'r':
         cout << "remove" << endl;
         break;
      case 'a':
         cout << "srch by artist" << endl;
         break;
      case 'b':
         cout << "srch by album" << endl;
         break;
      case 'q':
         cout << "quit" << endl;
         break;
      default:
         cout << "please enter in a valid selection" << endl;
         break;
    }
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
   if (loaded == false){
      cout << "file does not exist, exiting, please create a songs.txt file" << endl;
      exit(1);
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
      cout << "Field cannnot be empty. Please enter in some." << endl;
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
   bool valid = strlen(song.title) 
       && strlen(song.artist) 
       && strlen(song.duration_minutes) 
       && strlen(song.duration_seconds) 
       && strlen(song.album);

   return valid;
}

