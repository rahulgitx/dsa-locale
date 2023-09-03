#include <bits/stdc++.h>
using namespace std;

int helper(int n, int e, int** dp){
    if(dp[n][e] != -1){
        return dp[n][e];
    }

    int temp, minval = INT_MAX;
    for(int k=2; k<=n; k++){
        temp = max(helper(k-1, e-1, dp), helper(n-k, e, dp)) + 1;
        minval = min(temp, minval);
    }
    dp[n][e] = minval;
    return dp[n][e];
}

int memo(int n, int e){
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[e+1];
        for(int j=0; j<e+1; j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            else if(j == 1){
                dp[i][j] = i;
            }
            else if(i<=1){
                dp[i][j] = i;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
 
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<e+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return helper(n, e, dp);
}

int eggdrop(int n, int e){
    if(e == 1){
        return n;
    }
    if(n <= 1){
        return n;
    }

    int temp, minval = INT_MAX;
    for(int k = 2; k <= n; k++){
        temp = max(eggdrop(k-1, e-1), eggdrop(n-k, e)) + 1;
        // cout << "minval: " << minval << endl;
        minval = min(temp, minval);
    }
    return minval;
}

int main(){
    int k, n;
    cin >> n >> k;
    cout << memo(n, k);
}

/*
14 3
ans=4
*/
/*
6 2
ans=3
*/
