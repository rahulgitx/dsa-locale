#include <bits/stdc++.h>
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
    cout << output << endl;
    vector<int> v(1);
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    
}