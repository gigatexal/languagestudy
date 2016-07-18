#include "Song.h"

class DB { 
   public:
      DB();//TODO at least set size = 0
      static unsigned const int maxSize = 1024;


   private:
      Song songs[DB::maxSize];
};  
