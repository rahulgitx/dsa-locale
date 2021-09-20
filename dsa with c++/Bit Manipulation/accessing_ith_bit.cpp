#include <iostream>
#include <stdio.h>
using namespace std;

int ith(int n, int pos){
    int temp = (1<<(pos-1));
    // cout << "temp: " << temp << endl;
    // cout << "n: " << n << endl;
    if( (n&temp) != 0){
        return 1;
    }
    else{
        return 2;
    }


}

int main(){
    int n = 555;
    int pos = 6;
    // cout << "no of set bits " << __builtin_popcount(n) << endl;
    int output = ith(n, pos);
    cout << output;
    
}