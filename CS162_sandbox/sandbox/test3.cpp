#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct PEOPLE {
   string name;
   int height;
};   


int main(){
   vector<PEOPLE> peeps;
   for (int i = 0; i < 10; i++){
      PEOPLE p; 
      p.name = "test";
      p.height = i;
      peeps.push_back(p);
}

for (vector<PEOPLE>::iterator it = peeps.begin(); it != peeps.end(); it++){
   cout << it->name << " " << it->height << endl;
}

return 0;
}

