#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct test {
   char *str;
};

void _toLower(const char in[], const unsigned int size_in, char out[], const unsigned int size_out);

int main(){

char s[128];
strncpy(s,"THIS",sizeof(s));
cout << s << endl;

char ss[128];

_toLower(s,sizeof(s),ss,sizeof(ss));

cout << ss << endl;


return 0;

}

void _toLower(const char in[], const unsigned int size_in, char out[], const unsigned int size_out){
   if (size_in == size_out){
   for (int i = 0; i < size_in; i++){
      out[i] = tolower(in[i]);
      }
   }
}
