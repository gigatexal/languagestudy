#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DB.h"
#include "UI.h"
#include <iomanip>
using namespace std;

const int MAX_SONGS = 100;
const char songsFile[128] = "songs.txt";

void showAllSongs(DB& db);


int main(){
   UI ui;
   DB database;
   database.loadData(songsFile);
   Song song;
   cout << "Welcome to the songs database " << endl;

   ui.displayChoices();
   ui.displaySongHeader();
   showAllSongs(database);

   return 0;
}
/*
void UI::displaySongHeader(){
      cout << setw(10) << left << "Index"
           << setw(30) << left << "Title"
           << setw(45) << left << "Artist"
           << setw(10) << left << "Duration"
           << setw(20) << left << "Album"
           << endl;
}
*/

void showAllSongs(DB& db){
         for (int i = 0; i < db.getCurrSize(); i++){
             Song s = db.get(i);
             cout << setw(10) << left << i
                 << setw(30) << left << s.getTitle()
                 << setw(45) << left << s.getArtist()
                 << setw(5) << right << s.getLengthMinutes() << "m" 
                 << setw(5) << left << s.getLengthSeconds() 
                 << setw(20) << left << s.getAlbum()
                 << endl;
         }

}
