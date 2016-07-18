#include "Song.h"
#include <iostream>//can remove when not debugging
#include <cstring>

//set some initial dummy variables
Song::Song(){
   strncpy(_title,"title",Song::MAX_CHAR);
   strncpy(_artist,"artist",Song::MAX_CHAR);
   strncpy(_album,"album",Song::MAX_CHAR);
   _length_minutes = 0;
   _length_seconds = 0;
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

//getters
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

void Song::print() const {
   std::cout << this->getTitle() 
        << " : " 
        << this->getArtist()
        << " : "   
        << this->getAlbum()
        << " : "
        << this->getLengthMinutes()
        << " : "
        << this->getLengthSeconds()
        << std::endl;
}    
/*
const char* getSongRuntime() const{
   char runtime[Song::MAX_CHAR];
   strncpy(runtime,"test",sizeof(runtime));
   return runtime;
   //strncpy(runtime,
}
*/















