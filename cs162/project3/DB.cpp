#include "DB.h"
/*
class DB {
   public:
      DB();
      void add(Song s);
      void add(Song s, unsigned int index);
      void remove(unsigned int index);
      unsigned int getCurrSize() const;
   private:
      Song songs[DB::maxSize];
      int currSize;
      int maxSize;
};
*/

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

void DB::remove(unsigned int index){
   if ((this->currSize > 0) && (this->currSize < maxSize)){
      for (int i = 0; i < currSize; i++){
         this->songs[i] = this->songs[i+1];
      }
      this->currSize--;
   }
}

/*
//add to DB class
struct Loader {
   char title[128];
   char artist[128];
   char album[128];
   char length_minutes[128];
   char length_seconds[128];
};

fstream in("test.txt");

//put this into DB class
Loader l;

int i = 0;
while (      in.getline(l.title,Song::MAX_CHAR,';')
          && in.getline(l.artist,Song::MAX_CHAR,';')
          && in.getline(l.album,Song::MAX_CHAR,';')
          && in.getline(l.length_minutes,Song::MAX_CHAR,';')
          && in.getline(l.length_seconds,Song::MAX_CHAR,'\n')
          && i < 100){
             Song s(l.title,l.artist,l.album,atoi(l.length_minutes),atoi(l.length_seconds));
             songs[i] = s;
             i++;
      }
*/
