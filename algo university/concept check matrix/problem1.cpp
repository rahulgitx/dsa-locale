#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<long long int> input;
    int temp;
    for(int i=0; i<n*m; i++){
        cin >> temp;
        input.push_back(temp);
    } 
    if(n*m != c*r){
        for(int i=0; i<n*m; i++){
            cout << input[i] << " ";
            if((i+1)%m == 0){
                cout << endl;
            }
        }
    }

    else{
        for(int i=0; i<n*m; i++){
            cout << input[i] << " ";
            if((i+1)%c == 0){
                cout << endl;
            }
        }
    }
}