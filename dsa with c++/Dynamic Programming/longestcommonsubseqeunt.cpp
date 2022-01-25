#include <bits/stdc++.h>
using namespace std;

//tabulation
int longestdp(const string &x, const string &y, int n, int m){
    // initialization
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

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<m+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

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

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<m+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][m];
}


//memoization
int helper(const string &x, const string &y, int n, int m, int** dp){
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(x[n-1] == y[m-1]){
        dp[n][m] = 1 + helper(x, y, n-1, m-1, dp);
    }
    else{
        dp[n][m] = max(helper(x, y, n-1, m, dp), helper(x, y, n, m-1, dp));
    }

    return dp[n][m];
}
int longestmemo(const string &x, const string &y, int n, int m){
    // initialization
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

    return helper(x, y, n, m, dp);
}

//recursive approach 
int longest(const string &x, const string &y, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return (1+longest(x, y, n-1, m-1));
    }
    else{
        return max(longest(x, y, n-1, m), longest(x, y, n, m-1));
    }
}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);
    cout << longestdp(x, y, x.length(), y.length());
}

/*
ABCD
BACDBDCD
ans=4
*/

/*
abcde
ace
ans=3
*/

/*
abc
abc
ans=3
*/

/*
abc
def
ans=0
*/