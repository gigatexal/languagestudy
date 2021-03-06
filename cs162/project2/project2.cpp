#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
//making the duration_minutes and duration_seconds fields character arrays was a mistake
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
int countSongs(Song songs[]);
void displaySongs(const Song songs[]);
void displayChoices();
void addSong(Song songs[]);
void removeSong(Song songs[]);
void _toLower(const char in[], const unsigned int size_in, char out[], const unsigned int size_out);
void displaySong(const Song song, int index);
void displaySongsByGivenArtist(Song song[], const unsigned int size);
void displaySongHeader();
void displaySongsByGivenAlbum(Song song[], const unsigned int size);

int main(){
   //greeting
   cout << setw(80) << left << "WELCOME TO THE SONGS DATABASE\n" << endl;
   //DB
   Song songs[MAXSONGS];
   //Populate DB
   get(songs,FILENAME,getNumLines(FILENAME));
   //Initial display
   displaySongs(songs);
   //begin UI
   char input = 'n';
   char testME[CHAR_MAX];
   strncpy(testME,"Blink 182",sizeof(testME));
   while (input != 'q'){
   displayChoices();
   cout << endl;
   cout << "Enter in your selection here: ";
   get(input);
   switch (input){
      case 'n': 
         addSong(songs);
         break;
      case 'd':
         displaySongs(songs);
         break;
      case 'r':
         removeSong(songs);
         displaySongs(songs); 
         break;
      case 'a':
         displaySongsByGivenArtist(songs, sizeof(songs)/sizeof(Song));
         cout << endl; 
         break;
      case 'b':
         displaySongsByGivenAlbum(songs,sizeof(songs)/sizeof(Song));
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

void displaySongsByGivenArtist(Song song[], const unsigned int size){
   cout << "Enter in an artist's name : ";
   char name[CHAR_MAX];
   get(name,sizeof(name));
   int index = 0;
   displaySongHeader();
   while (index < size){
   if (strcmp(song[index].artist,name)==0){
      displaySong(song[index],index);
   }
   index++;
   }
}

void displaySongsByGivenAlbum(Song song[], const unsigned int size){
   cout << "Enter in an album title : ";
   char name[CHAR_MAX];
   get(name,sizeof(name));
   int index = 0;
   displaySongHeader();
   while (index < size){
   if (strcmp(song[index].album,name)==0){
      displaySong(song[index],index);
   }
   index++;
   }
}
//print out a simple header
void displaySongHeader(){
      cout << setw(10) << left << "Index"
           << setw(30) << left << "Title"
           << setw(45) << left << "Artist"
           << setw(10) << left << "Duration"
           << setw(20) << left << "Album"
           << endl;
}

//given a song, display it
void displaySong(const Song song, int index){
      char duration[CHAR_MAX];
      strcpy(duration,"");
      cout << setw(10) << left << index
           << setw(30) << left << song.title
           << setw(45) << left << song.artist
           << setw(10) << left << strcat(strcat(strcat(duration,song.duration_minutes),":"),song.duration_seconds)
           << setw(20) << left << song.album
           << endl;
}

//_toLower is a non-mutating lower-caser, passing in an input cstring, and size and get an output cstring given it's size
void _toLower(const char in[], const unsigned int size_in, char out[], const unsigned int size_out){
   if (size_in == size_out){
   for (int i = 0; i < size_in; i++){
      out[i] = tolower(in[i]);
      }
   }
}

//delete a song given an index, does bounds checking
void removeSong(Song songs[]){
   int length = countSongs(songs);
   if (length == 0){
      cout << "************* There are no songs to delete. *************** " << endl;
      return;
   } 
   int index;
   cout << "\nDelete a song from the database." << endl;
   cout << "Enter the index of the song you wish you delete: ";
   get(index); 
   while (index <= length){
      songs[index] = songs[index+1];
      index++;
   }   
   cout << "The song has been deleted. " <<endl;
}

//add a song to the inmemory database
void addSong(Song songs[]){
   unsigned int length = countSongs(songs);
   Song temp;
   unsigned int duration_minutes;
   unsigned int duration_seconds;
   cout << "Enter in the song's title: ";
   get(temp.title,CHAR_MAX);
   cout << "Enter in the song's artist: ";
   get(temp.artist,CHAR_MAX);
   cout << "Enter in the song's duration in minutes: ";
   get(temp.duration_minutes,CHAR_MAX);
   cout << "Enter in the song's duration in seconds (prepend a zero for entries less than 10 seconds): ";//atoi
   get(temp.duration_seconds,CHAR_MAX);   
   cout << "Enter in the album the song belongs to: ";
   get(temp.album,CHAR_MAX);
   if (length < MAXSONGS && isValid(temp)){
      songs[length++] = temp;
   }
}

//UI helper
void displayChoices(){
   cout << setw(80) << left << "Enter in a new song's info " << right << "(n)" << endl;
   cout << setw(80) << left << "Show or display songs current loaded " << right << "(d)" << endl;
   cout << setw(80) << left << "Delete or remove a song by a given index " << right << "(r)" << endl;
   cout << setw(80) << left << "Search for songs by artist " << right << "(a)" << endl;
   cout << setw(80) << left << "Search for songs by album " << right << "(b)" << endl;
   cout << setw(80) << left << "Terminate or quit the program " << right << "(q)" << endl;
}

//display all songs currently loaded
void displaySongs(const Song songs[]){
   //header
   displaySongHeader();
   int index = 0;
   while (isValid(songs[index])){
   char duration[CHAR_MAX];
   strcpy(duration,"");
   cout << setw(10) << left << index
        << setw(30) << left << songs[index].title 
        << setw(45) << left << songs[index].artist
        << setw(10) << left << strcat(strcat(strcat(duration,songs[index].duration_minutes),":"),songs[index].duration_seconds)  
        << setw(20) << left << songs[index].album
        << endl;
        index++;
   }
   cout << endl;
}

//helper to get length of Songs array
int countSongs(Song songs[]){
   int i = 0;
   for (; isValid(songs[i]); i++);
   return i;
}     

//load songs from the filesystem   
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

//write out songs to the filesystem
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

//checks that there's at least one character in each field
bool isValid(Song song){
   bool valid = strlen(song.title) 
       && strlen(song.artist) 
       && strlen(song.duration_minutes) 
       && strlen(song.duration_seconds) 
       && strlen(song.album);

   return valid;
}

