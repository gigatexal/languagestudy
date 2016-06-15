#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct book_meta_data {
   string name;
   string author;
};

vector<book_meta_data> books;

/* for testing only */
string filename = "//home//gigatexal//languagestudy//CS161//sandbox//data.txt";

bool compare(const book_meta_data& a, const book_meta_data& b){
   return a.author.compare(b.author);
}

int main(){
   fstream f;
   f.open(filename.c_str());
   book_meta_data b;
   int i = 0;
   string line;
   while ( getline(f,b.name) && getline(f,b.author) && 
          ++i){
            books.push_back(b);
          }
   
   cout << books.size() << endl; 
   sort(books.begin(), books.end(), compare);
   for (vector<int>::size_type i = 0; i != books.size(); i++){
      cout << books[i].name << " " << books[i].author << endl;
}

   sort(books.begin(), books.end(), compare);
   return 0;
}

