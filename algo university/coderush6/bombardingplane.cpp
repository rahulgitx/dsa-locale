#include <bits/stdc++.h>
using namespace std;

int bombard(int n){
    vector<int> v(n, 2);
    int attackcount = 0;
    for(int i=n-1; i>=0; i++){
        if(i != 0){
            v[i] = v[i]-1;
            v[i-1]++;
        }

    }
}


int main(){
    int n;
    cin >> n;
    bombard(n);
}