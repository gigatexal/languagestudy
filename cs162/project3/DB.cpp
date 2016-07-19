#include <fstream>
#include <iostream>
#include "DB.h"

DB::DB(){
   this->currSize = 0;
}

unsigned int DB::getCurrSize() const {
   return this->currSize;
}

void DB::add(Song s){
   if (currSize < this->maxSize){
      this->songs[currSize] = s;
      this->currSize++;
   }
}

void DB::add(Song s, unsigned int index){
   if ((currSize < this->maxSize) && (index < this->maxSize)){
      this->songs[index] = s;
      this->currSize++;
   }
}   

Song DB::get(unsigned int index){
   return songs[index];
}

void DB::remove(unsigned int index){
   if ((this->currSize > 0) && (this->currSize < maxSize)){
      for (int i = 0; i < currSize; i++){
         this->songs[i] = this->songs[i+1];
      }
      this->currSize--;
   }
}
/*
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
*/

bool DB::save(char filename[1024]){
  std::ofstream file(filename);
  bool success = false;
  if (file){ 
     for (int i = 0; i < currSize; i++){
         file << songs[i].getTitle()         << ";"
              << songs[i].getArtist()        << ";"
              << songs[i].getLengthMinutes() << ";"
              << songs[i].getLengthSeconds() << ";"
              << songs[i].getAlbum()         << std::endl; 
     }
     success = true;
  }
  return success;
}
