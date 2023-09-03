#include <bits/stdc++.h>
using namespace std;

long long max(int a, long long b){
    if (a>b){
        return a;
    }
    return b;
}

long long hole(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    // long long int dp[n][2];
    // dp[0][0] = arr[0];
    // // if(arr[0]<0){
    // //     dp[0][1] = 0;
    // // }
    // // else{
    // //     dp[0][1] = arr[0];
    // // }
    // dp[0][1] = 0;
    // long long maxval = INT_MIN;
    // for(int i=1; i<n; i++){
    //     dp[i][0] = max(arr[i], arr[i]+dp[i-1][0]);
    //     dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
    //     maxval = max(dp[i][1], maxval);
    // }
    // return maxval;
    long long left[n];
    left[0] = 0;
    left[1] = arr[0];
    for(int i=2; i<n; i++){
        left[i] = max(arr[i-1], arr[i-1]+left[i-1]);
    }

    // for(int i=0; i<n; i++){
    //     cout << left[i] << " ";
    // }
    // cout << endl;

    long long right[n];
    right[n-1] = 0;
    right[n-2] = arr[n-1];
    for(int i=n-3; i>=0; i--){
        right[i] = max(arr[i+1], arr[i+1]+right[i+1]);
    }

    
    // for(int i=0; i<n; i++){
    //     cout << right[i] << " ";
    // }
    // cout << endl;

    long long ans[n];
    long long maxval=max(right[0]+arr[0], max(arr[0], right[0]) );
    for(int i=1; i<n; i++){
        ans[i] = max(max(left[i]+right[i]+arr[i], arr[i]+left[i]), max(arr[i], left[i]+right[i]));
        ans[i] = max(ans[i], arr[i]+right[i]);
        maxval = max(ans[i], maxval);
    }
    return maxval;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << hole(arr, n);
}

/*
6
-1 -2 3 4 -5 -6
*/