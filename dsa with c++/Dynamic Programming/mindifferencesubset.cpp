#include <bits/stdc++.h>
using namespace std;

int mindifference(int arr[], int n){
    int maxsum = 0;
    for(int i=0; i<n; i++){
        maxsum += arr[i];
    }

    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[maxsum+1];
        for(int j=0; j<maxsum+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<maxsum+1; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<maxsum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j] );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " ";
        }
        // cout << endl;
    }

    int mindiff = INT_MAX;
    for(int i=0; i<=(maxsum/2); i++){
        if(dp[n][i] == 1){
            mindiff = min(mindiff, maxsum - (2*i) );
            // cout << "midiff: " << mindiff << " ";
        }
        
    }
    return mindiff;
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }    

    cout << mindifference(arr, n);
}

/*
4
1 6 11 5
ans=2
*/

/*
2
1 4
*/
