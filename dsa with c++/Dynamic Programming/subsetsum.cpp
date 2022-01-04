#include <bits/stdc++.h>
using namespace std;

//tabulation dp method
bool subsetsumtabulation(int n, int arr[], int sum){
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }


    int x, y;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        // cout << endl;
    }
    return dp[n][sum];
} 



// memoization
bool helpermemo(int n, int arr[], int sum, int **dp){
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(arr[n-1] <= sum){
        dp[n][sum] = (dp[n-1][sum-arr[n-1]] || dp[n-1][sum]);
    }
    else{
        dp[n][sum] = dp[n-1][sum];
    }
    return dp[n][sum];
}

bool subsetsummemo(int n, int arr[], int sum){
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }

    if(helpermemo(n, arr, sum, dp)){
        return 1;
    }
    else{
        return 0;
    }
}

//brute force recursion
// int subsetsumhelper(int n, int arr[], int sum){
//     if(n == 0){
//         return 0;
//     }
//     if(arr[n-1] <= sum){
//         int x = arr[n-1] + subsetsumhelper(n-1, arr, sum-arr[n-1]);
//         int y = subsetsumhelper(n-1, arr, sum);
//         if(x == sum){
//             return x;
//         }
//         else if(y == sum){
//             return y;
//         }
//         else{
//             return 0;
//         }
//     }
//     else{
//         int x = subsetsumhelper(n-1, arr, sum);
//         if(x == sum){
//             return sum;
//         }
//         else{
//             return 0;
//         }
//     }
// }

// int subsetsum(int n, int arr[], int sum){
//     if(subsetsumhelper( n, arr, sum)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

bool subsetsum(int n, int arr[], int sum){
    if(sum <= 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(arr[n-1] <= sum){
        return (subsetsum(n-1, arr, sum-arr[n-1]) || subsetsum(n-1, arr, sum));
    }
    else{
        return subsetsum(n-1, arr, sum);
    }
}
int main(){
    int n, sum; 
    cin >> n >> sum;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << subsetsumtabulation(n, arr, sum);
}


/*
6 9
3 34 4 12 5 2
ans=1
*/

/*
6 30
3 34 4 12 5 2
ans=0
*/