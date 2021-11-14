#include <iostream>
using namespace std;

void inttobin(int n){
    for(int i=31; i>=0; i--){
        int k = (n >> i);      //right shift the bits starting from MSB
        cout << (k&1) ; // gives output in integer form.
    }
}

int main(){
    inttobin(7);
}