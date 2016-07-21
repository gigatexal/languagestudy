#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DB.h"
//#include "UI.h"
#include <iomanip>
using namespace std;

const int MAX_SONGS = DB::maxSize;
const char songsFile[128] = "songs.txt";

void greeting();
void displayMenu();
void displaySongHeader();
Song newSong();
bool findSongsByArtist(char artist[]);
bool findSongsByAlbum(char album[]);
template <class T> void get(T &var);
void get(char str[], unsigned int size);

int main(){
   DB database;
   bool hasData = database.loadData(songsFile);
   if (hasData){
      displayMenu();
   }
   Song s = newSong();
   database.add(s);
   displaySongHeader();
   cout << database.get(database.getCurrSize()-1).getTitle() << endl;     
   return 0;
}

void greeting(){
   cout << "Welcome to the Songs library " << endl;
}

Song newSong(){
      /*
      void setTitle(char* title);
      void setArtist(char* artist);
      void setAlbum(char* album);
      void setLengthMinutes(int length_minutes);
      void setLengthSeconds(int length_seconds);
      */
   struct Loader {
      char title[DB::maxSize];
      char artist[DB::maxSize];
      char album[DB::maxSize];
      int length_minutes[DB::maxSize];
      int length_seconds[DB::maxSize];
   };
   Loader l;
   cout << "Enter in the song's title ";
   get(l.title,DB::maxSize);
   cout << "Enter in the song's artist ";
   get(l.artist,DB::maxSize);
   cout << "Enter in the song's album ";
   get(l.album,DB::maxSize);   
   cout << "Enter in the song's length in minutes ";
   int minutes = 0;
   get(minutes);
   cout << "Enter in the song's length in seconds ";
   int seconds = 0;
   get(seconds);
   Song s(l.title,l.artist,l.album,minutes,seconds); 
   return s;
}
    

void displayMenu(){
   cout << setw(80) << left << "Enter in a new song's info " << right << "(n)" << endl;
   cout << setw(80) << left << "Show or display songs current loaded " << right << "(d)" << endl;
   cout << setw(80) << left << "Delete or remove a song by a given index " << right << "(r)" << endl;
   cout << setw(80) << left << "Search for songs by artist " << right << "(a)" << endl;
   cout << setw(80) << left << "Search for songs by album " << right << "(b)" << endl;
   cout << setw(80) << left << "Terminate or quit the program " << right << "(q)" << endl;
}

void displaySongHeader(){
      cout << setw(10) << left << "Index"
           << setw(30) << left << "Title"
           << setw(45) << left << "Artist"
           << setw(10) << left << "Duration"
           << setw(20) << left << "Album"
           << endl;
}

template<class T> void get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cout << "Data entered was invalid" << endl;
      cin.clear();
      cin.ignore(DB::maxSize,'\n');
      cin >> val;
   }
   cin.ignore(DB::maxSize,'\n');
   var = val;
}

void get(char str[], unsigned int size){
   cin.get(str, size, '\n');
   while(!cin){
      cout << "Field cannnot be empty. Please enter in something." << endl;
      cin.clear();
      cin.ignore(DB::maxSize,'\n');
      cin.get(str, size, '\n');
   }
   cin.ignore(DB::maxSize,'\n');
}


