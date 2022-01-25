#include <bits/stdc++.h>
using namespace std;

int longest(string &x, string &y, int n, int m){
    //initialization
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

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int maxim = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
            maxim = max(dp[i][j], maxim);
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return maxim;
}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);
    cout << x << " " << y << endl;
    cout << longest(x, y, x.length(), y.length());
}

/*
abcdgh
acdghr
ans=4
*/

/*
abc
acb
*/