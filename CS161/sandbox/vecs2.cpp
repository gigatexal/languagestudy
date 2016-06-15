#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

struct books {
   string author;
   string title;
};

bool compareByLength(const data &a, const data &b)
{
    return a.word.size() < b.word.size();
}

int main(){
   books b;
   b.author = "dmv";
   b.title = "driving rules";
   
   books b1;
   b1.author = "e-commerce .co";
   b1.title = "how to make money on the internet";
   
   vector<books> v;
   v.push_back(b);
   v.push_back(b1);

   cout << v.at(0).author << " : " << v.at(1 .author << endl;
   
   sort(v.begin(), v.end(), compareByLength);

   cout << v.at(0).author << endl; 

return 0;
}
