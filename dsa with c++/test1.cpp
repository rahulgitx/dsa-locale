#include <bits/stdc++.h>
using namespace std;

void printBinary(int a){
    for(int i=31; i>=0; i--){
        if(((1<<i)&a)>>i) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main(){
    int a = INT_MIN;
    // a &= -a;
    int b = a & (-a);
    cout << b;
    // printBinary(a);
    // a = -a;
    // printBinary(a);
}