class UI {
   public: 
      static const unsigned int MAX_CHAR = 1024;
      void displaySongHeader();
      void displayChoices();
      template <class T> void get(T &var);
      void get(char str[], unsigned int size);
};      
