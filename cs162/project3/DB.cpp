#include "DB.h"
/*
class DB {
   public:
      DB();
      static unsigned const int maxSize = 1024;
      void add(Song s);
      void add(Song s, unsigned int index);
      void remove(unsigned int index);
      unsigned int getCurrSize() const;
   private:
      Song songs[DB::maxSize];
      int currSize;
};
*/

DB::DB() {
   this->currSize = 0; 
}

unsigned int DB::getCurrSize() const {
   return this->currSize;
}

void DB::add(Song s){
   if (currSize < this->maxSize){
      songs[currSize] = s;
   }
   currSize++;
}

void DB:add(Song s, unsigned int index){
   if ((currSize < this->maxSize) && index    
   

