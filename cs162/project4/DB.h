#include "Song.h"
#include <cstdlib>

class DB {
   public:
      static const unsigned int maxSize = 1024;
      DB();
      //getters
      void add(Song s);
      void add(Song s, unsigned int index);
      Song get(unsigned int index);
      const unsigned int getCurrSize() const;
      const void showAll() const;     
      //setters
      void remove(unsigned int index);
      bool save(char filename[1024]);//made large to accomodate a long path  
      bool loadData(const char filename[]);     
 
   private:
      Song songs[DB::maxSize];
      int currSize;
      //int computeInitialSize
};

/*
   ifstream f("songs.txt");
   int i = 0;
   char dummyLine[5];
   while (f.getline(dummyLine,5)){
      ++i;
   }
*/
