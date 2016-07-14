class Song {
   static const int MAX_CHAR = 1024;
   public:
      Song();
      Song(char* title, char* artist, char* album, int length_minutes; int length_seconds);
      ~Song();
      //setters
      void  setTitle(const char* title);
      char* getTitle() const;

   private:
      char* _title;
      char* _artist;
      char* _album;
      int _length_minutes;
      int _length_seconds;      
};

