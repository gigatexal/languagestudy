#include "Song.h"

class DB {
   public:
      static const unsigned int maxSize = 1024;
      DB();
      void add(Song s);
      void add(Song s, unsigned int index);
      void remove(unsigned int index);
      unsigned int getCurrSize() const;

   private:
      Song songs[DB::maxSize];
      int currSize;
};
