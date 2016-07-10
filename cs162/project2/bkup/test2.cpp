#include <iostream>
#include <cstring>
using namespace std;

struct test {
   char *str;
};

int main(){
test t;
strcpy(t.str,"this is a test");
cout << t.str << endl;
strcpy(t.str,"");
cout << t.str << endl;

char tst[127];
cout << strncpy(tst,

"127 woot sakldjflksjdflksjdflkjasdlkfjslkdjf;lskdjflk;sjdflksjaflksajdflksjadflk;sjaflaksjdflksajdflsakdjflksajdflskajdflskjdflksdjflsakjdflskajdflsakjdflksajdsalkjdfklsjdflkjsdfkljsakljflskajdflksadjfklsdajflksajdflk;sajdfkl;sajdflksadjfsklajflka;sjdflksajdfskla;jdfslkajfslk;ajfsak;ljfs;klajfsalk;jfsakl;jdfslkajfslka;djfsal;kjdflk;asjdflsk;ajfsl;kadjfslka;jfs;alkjdfslak;jfsalk;jdflsakjdfsalkjdfsklajflksa;jflskajdflk;sajfslk;ajdfklsajdfslkajflskajfdlskajdfslakjfslak;jdfslkajfsalkjfsalk;jdfsla;kdjfsalkjfslakdjfsalkdjfslakdjflsakjdflsa;kdjflask;jfslak;jdfaslkdjfslkadjflska;djfaslk;djfslkadjfslakdjfslakdjfaslkjdfalskdjf;lkasdjf;lksadjf;lksadjf;lkasdjfklsadjf;lksadjff"

,sizeof(tst)) << endl;

char *s = "127 woot sakldjflksjdflksjdflkjasdlkfjslkdjf;lskdjflk;sjdflksjaflksajdflksjadflk;sjaflaksjdflksajdflsakdjflksajdflskajdflskjdflksdjflsakjdflskajdflsakjdflksajdsalkjdfklsjdflkjsdfkljsakljflskajdflksadjfklsdajflksajdflk;sajdfkl;sajdflksadjfsklajflka;sjdflksajdfskla;jdfslkajfslk;ajfsak;ljfs;klajfsalk;jfsakl;jdfslkajfslka;djfsal;kjdflk;asjdflsk;ajfsl;kadjfslka;jfs;alkjdfslak;jfsalk;jdflsakjdfsalkjdfsklajflksa;jflskajdflk;sajfslk;ajdfklsajdfslkajflskajfdlskajdfslakjfslak;jdfslkajfsalkjfsalk;jdfsla;kdjfsalkjfslakdjfsalkdjfslakdjflsakjdflsa;kdjflask;jfslak;jdfaslkdjfslkadjflska;djfaslk;djfslkadjfslakdjfslakdjfaslkjdfalskdjf;lkasdjf;lksadjf;lksadjf;lkasdjfklsadjf;lksadjff";
cout << s << endl;

cout << strlen (s) << endl;

return 0;
}
