#include <bits/stdc++.h>
using namespace std;

int subsetsumtabulation(int n, int arr[], int sum){
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    int x, y;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                // cout << "arr[i-1]: " << arr[i-1] << " sum: " << j << " ";  
                x = arr[i-1] + dp[i-1][j-arr[i-1]];
                y = dp[i-1][j];
                if(x == j){
                    dp[i][j] = x;
                }   
                else if(y == j){
                    dp[i][j] = y;
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else{
                x = dp[i-1][j];
                if(x == j){
                    dp[i][j] = x;
                }
                else{
                    dp[i][j] = 0;
                }
            }
            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " ";
        }
        // cout << endl;
    }
    return dp[n][sum];
} 

bool subsetsumdp(int n, int arr[], int sum){
    if(subsetsumtabulation(n, arr, sum)){
        return 1;
    }
    else{
        return 0;
    }
}

int equalprt(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    else{
        return subsetsumdp(n, arr, sum/2);
    }
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // sort(arr, arr+n);
    cout << equalprt(arr, n);
}

/*
4
1 5 11 5
*/

/*
3
1 3 5 
*/


/*
5
2 4 11 10 5
ans=1
*/