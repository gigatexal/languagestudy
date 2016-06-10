#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){

int x = 32;
float y = 62.93;
float z = 781.92;


cout << fixed << showpoint;
cout << setprecision(2);
cout << "123456789012345678901234567890"<<endl;
cout << left << setw(5) << "Hi"<<right<<setw(5)<<x<<setw(7)<<y<<setw(7)<<z<<endl;



return 0;

}


