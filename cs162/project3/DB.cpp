#include <fstream>
#include <iostream>
#include "DB.h"

DB::DB(){
   this->currSize = 0;
}

const unsigned int DB::getCurrSize() const {
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
   if ((this->currSize > 0) && (this->currSize < maxSize) && (index <= this->currSize)){
      for (int i = 0; i < currSize; i++){
         this->songs[i] = this->songs[i+1];
      }
      this->currSize--;
   }
}

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
  file.close();
  return success;
}

bool DB::loadData(const char filename[]){
   bool success = false;
   struct Loader {
      char title[128];
      char artist[128];
      char album[128];
      char length_minutes[128];
      char length_seconds[128];
   };
   Loader l;
   std::ifstream in(filename);
   int i = 0;
   while (   in.getline(l.title,Song::MAX_CHAR,';')
          && in.getline(l.artist,Song::MAX_CHAR,';')
          && in.getline(l.length_minutes,Song::MAX_CHAR,';')
          && in.getline(l.length_seconds,Song::MAX_CHAR,';')
          && in.getline(l.album,Song::MAX_CHAR,'\n')
          && i < Song::MAX_CHAR){
             Song s(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             songs[i] = s; 
             i++;
             success = true;
      }
   currSize = i;
   in.close();
   return success;    
}
