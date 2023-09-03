#include <bits/stdc++.h>
using namespace std;

int toeplitz(vector<vector<long long>> arr, int n, int m){
    for(int i=n-1; i>=0; i--){
        long long start = arr[i][0];
        int k = i+1; int j=1;
        // cout << "start: " << start << " i: " << i << " j: " << j << endl;
        while(k<n && j<m){
            // cout << arr[k][j] << " ";
            if(start == arr[k][j]){
                k++; j++;
            }
            else{
                return 0;
            }
        }
    }
    for(int j=1; j<m; j++){
        long long start = arr[0][j]; int i=1; int k = j+1;
        while(i<n && k<m){
            if(start == arr[i][k]){
                i++; k++;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    long long temp;
    vector<vector<long long>> v;
    for(int i=0; i<n; i++){
        vector<long long> vtemp;
        for(int j=0; j<m; j++){
            cin >> temp;
            vtemp.push_back(temp);
        }
        v.push_back(vtemp);
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << toeplitz(v, n, m);
}