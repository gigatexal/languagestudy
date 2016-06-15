/*****************************************************************
* Name: Alex Narayan
* HW: #6 - checksum
* Date: 5.29.2016
* Class: CS161
* Resources: StackOverflow, google
******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
//because arrays suck 90% of the time and this is c++; they also suit how i think better
#include <vector>
using namespace std;

void CLI();
string get_file_name();
int compute_checksum(string filename);
template <typename T> int find_file_at(T v, string file_path);

int main(){
	
	struct file_metadata {
		string file_and_path;
		unsigned int checksum;
	};
	//because keeping track of two indexes sucks
	vector<file_metadata> files;
	
	//variables to run the CLI 
	char choice;
	bool run = true;


	string filename;
	while (run){
		CLI();
		cin >> choice;
		file_metadata f;
		int vector_index = 0;
		int checksum = 0;
		switch (choice)
		{ 
			case 'a':
			case 'A':
				cin.ignore();
				filename = get_file_name();
				if (filename.length() < 1){
					break;
				}
				checksum = compute_checksum(filename);
				f.checksum = checksum;
				f.file_and_path = filename;
				files.push_back(f);
				break;
			case 'B':
			case 'b':
				cin.ignore();
				filename = get_file_name();
				if (filename.length() < 1){
					break;
				}
				checksum = compute_checksum(filename);
				if (vector_index != -1){
					//find the previous checksum
					if (checksum == files[vector_index].checksum){
						cout << "File checksum = " << checksum << endl;
						cout << '\t' << "The file integrity check has passed successfully (checksum = 0)" << endl;//not sure what checksum = 0 means, why not say they match, or there's no changes between the two?
						break;
					}
					else if (checksum != files[vector_index].checksum){
						cout << "File checksum = " << checksum << endl;
						cout << '\t' << "The file integrity check has failed (previous checksum = " << files[vector_index].checksum << ", new checksum = " << checksum << ")" << endl;
						break;
					}
				}
				cout << "File checksum = " << checksum << endl;
				cout << '\t' << "The checksum has not been computed on the file: " << filename << endl;
				break;
			case 'Q':
			case 'q':
				run = false;
				break;
			default:
				break;
		}
		

	}
	
	system("pause");
	return 0;
}
//given a filename, compute the checksum
int compute_checksum(string filename){
	ifstream file;
	const int MAX = 100000;//could just use a vector here too...
	char contents[MAX];
	file.open(filename.c_str(), ios::binary);
	int fileLength = 0;
	file.seekg(0, ios_base::end);
	fileLength = file.tellg();
	file.seekg(0, ios_base::beg);
	file.read(contents, fileLength);
	file.clear(ios::ios_base::goodbit);
	file.close();
    //compute checksum
	int checksum = 0;
	for (int i = 0; i < fileLength; i++){
		checksum += contents[i];
	}
	return checksum;
}

template <typename T> int find_file_at(T v, string file_path){//because passing in vector<files_metadata> didn't work
	int index = 0;
	int not_found = -1;
	for (; index != v.size(); ++index){
		if (v[index].file_and_path == file_path){
			break;
		}
	}
	if (index == v.size()){
		return not_found;
	}
	return index;
}

string get_file_name(){
	cout << "Specify the file path: ";
	string filename = "";
	getline(cin,filename);
	return filename;
}

void CLI(){
	cout << "Please select:" << endl;
	cout << "  " << "A) Compute checksum of the specified file" << endl;
	cout << "  " << "B) Verify integrity of specified file" << endl;
	cout << "  " << "Q) Quit" << endl;
}
