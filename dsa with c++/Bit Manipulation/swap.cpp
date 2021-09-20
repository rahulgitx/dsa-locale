#include <iostream>
using namespace std;

void swap(int &x, int &y){
    x ^= y;
    y ^= x;
    x ^= y;
}


int main(){
    int a = 8, b = 10;
    swap(a, b);
    cout << "a: " << a << " b: " << b;
}