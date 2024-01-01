#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    for(int i=0; i<64; i++){
        int x = (i ^ (i>>1));
        for(int j=5; j>=0; j--){
            cout << ((x&(1<<j))>>j);
        }
        // cout << " : " << i << " (";
        // for(int j=5; j>=0; j--){
        //     cout << ((i&(1<<j))>>j);
        // }
        // cout << ")" << endl;
        int ans = 3^x;
        cout << " ";
        for(int j=5;j>=0; j--){
            cout << ((ans&(1<<j))>>j);
        }
        cout << endl;
    }

}