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

   return 0;
}
