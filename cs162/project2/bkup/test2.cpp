#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct test {
   char *str;
};


int main(){

char s[128];

strncpy(s,"4",sizeof(s));
cout << s << endl;

int duration = atoi(s);

if (duration < 10){
   strncpy(s,"",sizeof(s));
   strncpy(strncpy(s,"0",sizeof(s)),char(duration),sizeof(s));
}
cout << s << endl;

return 0;

}
