#include <iostream>
using namespace std;

void check(int n){
    int temp = (n^(n>>1));
    if ( (temp&(temp+1)) == 0){
        cout << "alternate" << endl;
    }
    else{
        cout << "not alternate" << endl;
    }
}

int main(){
    int n = 85;
    check(n);
}