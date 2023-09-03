#include <bits/stdc++.h>
using namespace std;

//wrong
int mcmdp(int arr[], int n){
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i <= j || i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    int temp;
    int minans;
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int minval = INT_MAX;
            for(int k=i; k<j; k++){
                temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                // cout << "i: " << i << " j: " << j << " k: " << k << " mult " << arr[i-1]*arr[k]*arr[j];
                // cout << " dp[i][k]: " << dp[i][k] << " dp[k+1][j]: " << dp[k+1][j] << endl;
                minval = min(temp, minval);
            }
            dp[i][j] = minval;
            // minans = min(dp[i][j], minans);
            // dp[i][j] = dp[i][]
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[1][n-1];
}

int helper(int arr[], int i, int j, int** dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int temp, minval = INT_MAX;
    for(int k=i; k<j; k++){
        // cout << "k: " << k << endl;
        temp = helper(arr, i, k, dp) + helper(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];

        minval = min(minval, temp);
        // cout << "minval: " << minval << endl;
    }
    // cout << endl;
    dp[i][j] = minval;
    return minval;
    
}

int memoization(int arr[], int n){
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return helper(arr, 1, n-1, dp);
}

int mcm(int arr[], int i, int j){
    if(i >= j){
        return 0;
    }
    // cout << "i: " << i << " j: " << j << endl;
    int temp, minval = INT_MAX;
    for(int k=i; k<j; k++){
        // cout << "k: " << k << endl;
        temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        minval = min(minval, temp);
        cout << "minval: " << minval << endl;
    }
    cout << endl;
    return minval;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << mcmdp(arr, n);
}

/*
5
40 20 30 10 30
ans=26000
*/

/*
4
10 30 5 60
ans=4500
*/

