#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n];
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    int temp;
    for(int i=0; i<q; i++){
        cin >> temp;
        cout << mp[temp] << endl;
    }
}