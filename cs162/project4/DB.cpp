#include <fstream>
#include <iostream>
#include "DB.h"

DB::DB(){
   this->currSize = 0;
}

DB::~DB(){
   delete [] songs;
};

const unsigned int DB::getCurrSize() const {
   return this->currSize;
}
/*
void DB::growDB(){
   if (currSize > 2 * this->jumpAmount - 1){
      Song tmp = new Song[this->currSize + this->jumpAmount];
      for (int i = 0; i < currSize; i++){
         Song s = this->get(i);
         tmp[i] = s;
         delete s;
      }
      delete [] this->songs;
      this->songs = new Song[this->currSize + this->jumpAmount];
     } 
}
*/
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
   //return this->songs[index];
}

void DB::remove(unsigned int index){
   if ((this->currSize > 0) && (this->currSize < maxSize) && (index <= this->currSize) && (index > 0)){
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

//count the number of lines in teh file
//set the size of the db to this + 1
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
   char dummyLine[1024];
   while (in.getline(dummyLine,1024)){
      ++i;
   }
   delete [] this->songs;
   this->songs = new Song[i + (this->jumpAmount) ];
   
   in.close();
   in.open(filename);
   int count = 0;
   while (   in.getline(l.title,Song::MAX_CHAR,';')
          && in.getline(l.artist,Song::MAX_CHAR,';')
          && in.getline(l.length_minutes,Song::MAX_CHAR,';')
          && in.getline(l.length_seconds,Song::MAX_CHAR,';')
          && in.getline(l.album,Song::MAX_CHAR,'\n')
          ){
          
             Song s(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             this->add(s);
             /* 
             Song *s = new Song(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             this->songs[count] = s;             
             */
             success = true;
             count++;
   } 
   in.close();
   return success;    
}
