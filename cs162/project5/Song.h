class Song {
   public:
      Song();
      ~Song();
      Song(char* title, char* artist, char* album, int length_minutes, int length_seconds);
      static const int MAX_CHAR = 1024;
   
      //setters
      void setTitle(char* title);
      void setArtist(char* artist);
      void setAlbum(char* album);
      void setLengthMinutes(int length_minutes);
      void setLengthSeconds(int length_seconds);
      
      //getters
      const char* getTitle() const;
      const char* getArtist() const;      
      const char* getAlbum() const; 
      int         getLengthMinutes() const;
      int         getLengthSeconds() const;     
 
      //For Debug only
      void        print() const;

   private:
      char _title[Song::MAX_CHAR];
      char _artist[Song::MAX_CHAR];
      char _album[Song::MAX_CHAR];
      int _length_minutes;
      int _length_seconds;      
};

