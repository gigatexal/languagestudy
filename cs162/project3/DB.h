#include "Song.h"
class DB {
   public:
      static const unsigned int maxSize = 1024;
      DB();
      //getters
      void add(Song s);
      void add(Song s, unsigned int index);
      Song get(unsigned int index);
      unsigned int getCurrSize() const;
      const void showAll() const;     

      //setters
      void remove(unsigned int index);
      bool save(char filename[1024]);//made large to accomodate a long path  
 
   private:
      Song songs[DB::maxSize];
      int currSize;
};
