#include<string.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

enum color{
    Black,
    blue,
    red
};


long long func(int n, vector<vector<int>> arr){
    int ans = INT_MIN;
    // cout << "insed";

    int diffsum = 0;
    vector<int> diff(n, 0);
    for(int i=0; i<n; i++){
        diff[i] = arr[i][0] - arr[i][1];
        diffsum += diff[i];
    }

    // cout << "se";
    for(int i=0; i<n; i++){
        int a = diffsum - diff[i];
        int b = arr[i][0] - (-a);
        ans = max(ans, b );
    }

    return ans;
}


int main()
{
    // int k;
    // cin >> k;
    // for(int i=0; i<k; i++){
        int n;
        cin >> n;
        vector<vector<int>> v;
        for(int j=0; j<n; j++){
            vector<int> t;
            int a, b;
            cin >> a >> b;
            t.push_back(a);
            t.push_back(b);
            v.push_back(t);
        }
        cout << func(n, v);
    // }
}

/*
2
3
3 1
4 2
6 0
2
0 5
5 0
*/