#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DB.h"
//#include "UI.h"
#include <iomanip>
using namespace std;

const int MAX_SONGS = DB::maxSize;
char songsFile[128] = "songs.txt";

void greeting();
void displayMenu();
void displaySongHeader();
void displaySong(DB &db, int index);
void displayAllSongs(DB &db);
Song newSong();
bool findSongsByArtist(char artist[]);
bool findSongsByAlbum(char album[]);
template <class T> void get(T &var);
void get(char str[], unsigned int size);

int main(){
   DB database;
   bool hasData = database.loadData(songsFile);
   if (hasData){
      displaySongHeader();
      displayAllSongs(database);
      displayMenu();
   }
   Song s;
   char input = 'n'; 
   unsigned int secondaryInput = 0;
   char userEntry[128]; 
   while (input != 'q') {
   cout << "Enter in your selection here: ";
   get(input);
   
   switch (input){
      case 'n':
         s = newSong();
         database.add(s);
         cout << endl;
         displayMenu();
         cout << endl;
         break;
      case 'd':
         displayAllSongs(database);
         cout << endl;
         displayMenu();
         cout << endl;
         break;
      case 'r':
         cout << "Enter in the index of the song you wish to delete :";
         get(secondaryInput);
         database.remove(secondaryInput);
         cout << "Song deleted" << endl;
         displayAllSongs(database);
         cout << endl;         
         displayMenu();
         cout << endl;
         break;
      case 'a':
         cout << "Find all the songs by a given artist: enter in an artist here ";
         get(userEntry,128);
         displaySongHeader();
         for (int i = 0; i < database.getCurrSize(); i++){
            s = database.get(i);
            if (strcmp(s.getArtist(),userEntry) == 0){
               displaySong(database,i);
            }
         }   
         cout << endl;
         displayMenu();
         cout << endl;
         break;
      case 'b':
         cout << "Find all the songs in a given album: enter in the album here: ";
         get(userEntry,128);
         displaySongHeader();
         for (int i = 0; i < database.getCurrSize(); i++){
            s = database.get(i);
            if (strcmp(s.getAlbum(),userEntry) == 0){
               displaySong(database,i);
            }
         }
         cout << endl;
         displayMenu();
         cout << endl;
         break;
      case 's':
         database.save(songsFile);
         cout << "Saved songs currently Loaded to disk. " << endl;
         cout << endl;
         displayMenu();
         cout << endl;
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

void greeting(){
   cout << "Welcome to the Songs library " << endl;
}

Song newSong(){
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
   cout << setw(80) << left << "Save currently loaded songs to disk " << right << "(s)" << endl; 
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

void displaySong(DB &db, int index){
   int maxIndex = db.getCurrSize();
   if (index <= maxIndex){
      cout << setw(10) << left << index 
           << setw(30) << left << db.get(index).getTitle()
           << setw(45) << left << db.get(index).getArtist()
           << setw(4) << right << db.get(index).getLengthMinutes() << setw(1) << "m"
           << setw(4) << left << db.get(index).getLengthSeconds()
           << setw(20) << left << db.get(index).getAlbum()
           << endl;
   }  
}

void displayAllSongs(DB &db) {
   int maxIndex = db.getCurrSize();
   for (int i = 0; i < maxIndex; i++){
      displaySong(db,i);
   }
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


