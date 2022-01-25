#include <bits/stdc++.h>
using namespace std;

int subsequence(string &x, string &y, int n, int m){
    //initialization
    cout << "n: " << n << " m: " << m << endl;
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[m+1];
        for(int j=0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "m: " << m << " n: " << n << endl;
    return m+n-2dp[n][m];
}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);
    cout << subsequence(x, y, x.length(), y.length());
}

/*
abcd
xycd
ans=6
*/

/*
hxmngqmf
gnapcnty
ans=15
*/

/*
AVnQIELxFb
TEpRbSvi
ans=16
*/