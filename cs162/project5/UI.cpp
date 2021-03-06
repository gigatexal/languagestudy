#include "UI.h"
#include <iomanip>
#include <iostream>
using namespace std;

void UI::displayChoices(){
   cout << setw(80) << left << "Enter in a new song's info " << right << "(n)" << endl;
   cout << setw(80) << left << "Show or display songs current loaded " << right << "(d)" << endl;
   cout << setw(80) << left << "Delete or remove a song by a given index " << right << "(r)" << endl;
   cout << setw(80) << left << "Search for songs by artist " << right << "(a)" << endl;
   cout << setw(80) << left << "Search for songs by album " << right << "(b)" << endl;
   cout << setw(80) << left << "Terminate or quit the program " << right << "(q)" << endl;
}

void UI::displaySongHeader(){
      cout << setw(10) << left << "Index"
           << setw(30) << left << "Title"
           << setw(45) << left << "Artist"
           << setw(10) << left << "Duration"
           << setw(20) << left << "Album"
           << endl;
}


template <class T> void UI::get(T &var){
    T val;
    cin >> val;
    while (!cin){
      cout << "Data entered was invalid" << endl;
      cin.clear();
      cin.ignore(UI::MAX_CHAR,'\n');
      cin >> val;
   }
   cin.ignore(UI::MAX_CHAR,'\n');
   var = val;
}

void UI::get(char str[], unsigned int size){
   cin.get(str, size, '\n');
   while(!cin){
      cout << "Field cannnot be empty. Please enter in something." << endl;
      cin.clear();
      cin.ignore(UI::MAX_CHAR,'\n');
      cin.get(str, size, '\n');
   }
   cin.ignore(UI::MAX_CHAR,'\n');
}

