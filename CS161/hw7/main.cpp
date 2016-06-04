/*****************************************************************
* Name: Alex Narayan
* HW: #7B - library
* Date: 6.4.2016 -- the day muhammad ali died. :-(
* Class: CS161
* Resources: StackOverflow, google
******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector> //so much cooler than arrays, though more space needed
                  //oh well, greater abstractions come at a cost but worth it
#include <algorithm> //sorting, transforming for use of tolower

using namespace std;

string get_filename();
void greeting();
int loadData(string pathname);
void showAll();
int showBooksByAuthor(string name);
int showBooksByTitle(string title);
string _toLower(string s); 
void sortResults(string choice);


struct BOOKS {
	string title;
	string author;
};
vector<BOOKS> books;


int main(){
	greeting();
	bool run = true;
	char choice;
	string author_input;
	string title_input;
	int num_books_by_author_found = 0;
	int num_books_by_title_found = 0;

	int dataLoaded = loadData(get_filename().c_str());
	if (dataLoaded == 1){
		cout << books.size() << " records loaded successfully\n" << endl;

		while (run){
			cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";
			cin >> choice;
			cout << endl;
			switch (choice){
			
			case 'q':
			case 'Q':
				run = false;
				break;

			case 'A':
			case 'a':
				cin.ignore();
				cout << "Author's Name: ";
				getline(cin, author_input);
				num_books_by_author_found = showBooksByAuthor(author_input);
				cout << num_books_by_author_found << " records found." << endl;
				cout << endl;
				break;

			case 'T':
			case 't':
				cin.ignore();
				cout << "Title: ";
				getline(cin, title_input);
				num_books_by_title_found = showBooksByTitle(title_input);
				cout << num_books_by_title_found << " records found." << endl;
				cout << endl;
				break;

			case 'S':
			case 's':
				showAll();
				cout << books.size() << " records found." << endl;
				cout << endl;
				break;

			default:
				run = false;
				break;

			}
		}

	}

	system("pause");
	return 0;
}

string get_filename(){
	string filename;
	cout << "Please enter the name of the backup file: ";
	getline(cin, filename);
	return filename;
}

void greeting(){
	cout << "Welcome to Alex's Library Database. " << endl;
}

int loadData(string pathname){
	//requires a file with this structure:
	//title
	//author
	//title
	//author
	//...etc
	int success = 0;
	fstream file;
	if (pathname.length() > 0 && !pathname.empty()){
		file.open(pathname.c_str());
		success = 1;
	}
	BOOKS b;
	while (getline(file, b.title) && getline(file, b.author)){
		books.push_back(b);
	}
	//since the program is read once, show many, we just close the file here.
	if (file.is_open()){
		file.clear(std::ios_base::goodbit);
		file.close();
	}
	return success;
}

void showAll(){
	//sort by title?
	sortResults("title");
	for (vector<int>::size_type i = 0; i < books.size(); i++){
		cout << books[i].title << " (" << books[i].author << ")" << endl;
	}
}

int showBooksByAuthor(string name){
	int itemsFound = 0;
	string searchVal = _toLower(name);
	string author;
	//creating a vector of type int seems to be the only way to iterate by index with vectors
	for (vector<int>::size_type i = 0; i < books.size(); i++){
		author = _toLower(books[i].author);
		if (strstr(author.c_str(), searchVal.c_str())){
			cout << books[i].title << " (" << books[i].author << ")" << endl;
			itemsFound++;
		}
	}
	return itemsFound;
}

int showBooksByTitle(string name){
	int itemsFound = 0;
	string searchVal = _toLower(name);
	string title;
	//creating a vector of type int seems to be the only way to iterate by index with vectors
	for (vector<int>::size_type i = 0; i < books.size(); i++){
		title = _toLower(books[i].title);
		if (strstr(title.c_str(), searchVal.c_str())){
			cout << books[i].title << " (" << books[i].author << ")" << endl;
			itemsFound++;
		}
	}
	return itemsFound;
}

void sortResults(string choice){
	if (choice == "title"){
		//yay for anonymous functions aka lambda functions, it'd be dumb to have to maintain seperate
		//functions for sorting based on two fields of the struct
		sort(books.begin(), books.end(), [](BOOKS& a, BOOKS& b){ return a.title < b.title;  }); //from stackoverflow as well, really handy too
	}
	else if (choice == "author"){
		sort(books.begin(), books.end(), [](BOOKS& a, BOOKS& b){ return a.author < b.author;  });
	}
}

//totally stolen from stackoverflow - http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
string _toLower(string s){ //limitation: breaks on non-ascii characters though
	string lower = s;
	//use the STL to go through every 
	transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}

