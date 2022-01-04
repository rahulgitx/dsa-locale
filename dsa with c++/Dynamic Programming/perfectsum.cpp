//subsets sum with a given sum
#include <bits/stdc++.h>
using namespace std;


int perfectsum(int arr[], int n, int sum){
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
        for(int j=0; j<sum+1; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    // cout << "initialised dp" << dp[1][0];

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << "dp; " << endl;
    return dp[n][sum];

}

int main(){
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << perfectsum(arr, n, sum);
}


/*
6 10
2 3 5 6 8 10
ans=3
*/

/*
5 10
1 2 3 4 5
ans=3
*/