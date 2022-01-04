#include <bits/stdc++.h>
using namespace std;

// tabulation
int knapSackdp(int w, int wt[], int val[], int n){
    int dp[n+1][w+1];
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    cout << "dp[1][1]: " << dp[1][1] << endl;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if((wt[i-1]) > j){
                dp[i][j] = dp[i-1][j]; 
            }
            else{
                // if(j-wt[j-1] >= 0){
                    cout << " wt[]:  " << wt[j-1] << " ";
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                // }
                // else{
                //     dp[i][j] = max(val[i-1]+0, dp[i-1][j]);
                // }

            }
            cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " ";  
        }
        cout << endl;
    }
    // cout << "dp: " << dp[n][w];
    return dp[n][w];
}

//memoization
int helper(int w, int wt[], int val[], int n, int **dp){
    cout << "w: " << w << " n: " << n << endl;
    if(dp[w][n] != -1){
        return dp[w][n];
    }
    if(n == 0 || w <= 0){
        dp[w][n] = 0;
        return dp[w][n];
    }
    if(wt[n-1] <= w){
        dp[w][n] = max(val[n-1] + helper(w-wt[n-1], wt, val, n-1, dp), helper(w, wt, val, n-1, dp) );
    }    
    else{
        dp[w][n] = helper(w, wt, val, n-1, dp);
    }
    cout << "w: " << w << " n: " << n << " dp[w][n]: " << dp[w][n] << endl;
    return dp[w][n];
}
int knapSackmemo(int w, int wt[], int val[], int n){
    if(n == 0 || w == 0){
        return 0;
    }
    int **dp = new int*[w+1];
    for(int i=0; i<w+1; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;

    return helper(w, wt, val, n, dp);
}

// brute force solution
int knapSack(int w, int wt[], int val[], int n){
    if(n == 0 || w <= 0){
        return 0;
    }
    cout << "w: " << w << " n: " << n << endl;
    if(wt[n-1] <= w){
        return max(knapSack(w, wt, val, n-1), val[n-1] + knapSack(w-wt[n-1], wt, val, n-1));
    }    
    else{
        return knapSack(w, wt, val, n-1);
    }
}

int main(){
    int n, w;
    cin >> n >> w;
    int values[n], weights[n];
    for(int i=0; i<n; i++){
        cin >> values[i];
    }
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    cout << knapSackdp(w, weights, values, n);

}

/*
3 4
1 2 3
4 5 1
ans=3
*/

/*
3 4
1 2 3
1 5 1
ans=4
*/

/*
3 3
1 2 3
4 5 6
ans = 0
*/


/*
5 30
1 5 10 20 15
5 10 20 5 20
ans=36
*/