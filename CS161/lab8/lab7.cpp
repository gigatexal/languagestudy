#include <iostream>
#include <fstream>
using namespace std;
/*

inFile.open(filePath.c_str(), ios::binary);

inFile.seekg(0, ios_base::end);
int fileLen = inFile.tellg();
inFile.seekg(0, ios_base::beg);

inFile.read(charArr, fileLen);
inFile.close();

*/

int fileSize(ifstream file);

int main() {

   fstream file;
   file.open("test.txt");
   cout << fileSize(file);
   file.close();

   return 0;
}

int fileSize(ifstream file){
 return 0;
}


