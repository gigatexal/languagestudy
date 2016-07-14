#include "Song.h"
#include <cstring>
/*class Song {
   public:
      Song();
      Song(char* title, char* artist, char* album, int length_minutes, int length_seconds);
      static const int MAX_CHAR = 1024;

      //setters
      void setTitle(char* title);
      void setArtist(char* artist);
      void setAlbum(char* album);
      void setLengthMinutes(int length_minutes);
      void setLengthSeconds(int length_seconds);

      //getters
      const char* getTitle() const;
      const char* getArtist() const;
      const char* getAlbum() const;
      int         getLengthMinutes() const;
      int         getLengthSeconds() const;

   private:
      char _title[Song::MAX_CHAR];
      char _artist[Song::MAX_CHAR];
      char _album[Song::MAX_CHAR];
      int _length_minutes;
      int _length_seconds;
};
*/

//set some initial dummy variables
Song::Song(){
   strncpy(_title,"title",Song::MAX_CHAR);
   strncpy(_artist,"artist",Song::MAX_CHAR);
   strncpy(_album,"album",Song::MAX_CHAR);
   _length_minutes = 1;
   _length_seconds = 59;
}   

Song::Song(char* title, char* artist, char* album, int minutes, int seconds){
   strncpy(_title,title,Song::MAX_CHAR);
   strncpy(_artist,artist,Song::MAX_CHAR);
   strncpy(_album,album,Song::MAX_CHAR);
   _length_minutes = minutes;
   _length_seconds = seconds;
}
//setters
void Song::setTitle(char* title){
   strncpy(_title,title,Song::MAX_CHAR);
}

void Song::setArtist(char* artist){
   strncpy(_artist,artist,Song::MAX_CHAR);
}

void Song::setAlbum(char* album){
   strncpy(_album,album,Song::MAX_CHAR);
}

void Song::setLengthMinutes(int length_minutes){
   _length_minutes = length_minutes;
}

void Song::setLengthSeconds(int length_seconds){
   _length_seconds = length_seconds;
}

//
const char* Song::getTitle() const {
   return _title;
}

const char* Song::getArtist() const {
   return _artist;
}

const char* Song::getAlbum() const {
   return _album;
}

int Song::getLengthMinutes() const {
   return _length_minutes;
}

int Song::getLengthSeconds() const {
   return _length_seconds;
}




















