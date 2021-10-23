#include <iostream>
using namespace std;

int* func(int *x){
    *x = *x + 1;
}

int main(){
int *x = new int;
*x = 5;
int* output = func(x);
cout << *output << endl;
}