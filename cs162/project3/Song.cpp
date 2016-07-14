#include "Song.h"
#include <cstring.h>

Song::Song(){
   strncpy(_title,"title",);
   strncpy(_title,"artist",sizeof(_artist));
   strncpy(_title,"album",sizeof(_album));
   _length_minutes = 1;
   _length_seconds = 59;
}   

Song::Song(char* title, char* artist, char* album, int minutes, int length){
   strncpy();
   strncpy(_title,"artist",sizeof(_artist));
   strncpy(_title,"album",sizeof(_album));
   _length_minutes = 1;
   _length_seconds = 59;
}


