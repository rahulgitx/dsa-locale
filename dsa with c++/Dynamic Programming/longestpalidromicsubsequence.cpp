#include <bits/stdc++.h>
using namespace std;

int longest(string &x){
    int n = x.length();
    string y;
    for(int i=n-1; i>=0; i--){
        y.push_back(x[i]);
    }
    
    //initialization
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][n];
}

int main(){
    string x;
    getline(cin, x);
    cout << longest(x);
}

/*
agbcba
ans=5
*/

/*
bbbab
ans=4
*/

/*
cbbd
ans=2
*/