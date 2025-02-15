#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a, vector<int>& b){
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]){
        return a[1] < b[1];
    }
    else return false;
}

int main(){
    vector<vector<int>> v;
    vector<int> vTemp;
    int n, temp; cin >> n;
    for(int i=0; i<n; i++){

        cin >> temp; vTemp.push_back(temp);
        if(i%2){
            v.push_back(vTemp);
            vTemp.clear();
        }
    }

    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

   
}

/*
4 4 2 3 1
*/