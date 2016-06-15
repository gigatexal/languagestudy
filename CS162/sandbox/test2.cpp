using namespace std;

int main(){

int a[10];
for (int i = 0; i < 10; i++){
   a[i] = i;
}

int sum = 0;
for (int i = 0; i < 10; i++){
   sum += a[i];
}


return 0;
}
