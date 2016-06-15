#include <iostream>
#include <vector>
using namespace std;

int main(){
vector<int> vecs;
vecs.push_back(1);
vecs.push_back(2);
vecs.push_back(3);

for (vector<int>::iterator it = vecs.begin(); it != vecs.end(); it++){
   cout << *it << endl;
}


return 0;
}
