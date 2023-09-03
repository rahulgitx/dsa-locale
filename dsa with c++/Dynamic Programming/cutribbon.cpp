/*
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
*/

#include <bits/stdc++.h>
using namespace std;

int cutribbon(int n, int arr[]){
    // initialization
    int** dp = new int*[4];
    for(int i=0; i<4; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            if(i == 0){
                dp[i][j] = INT_MIN;
            }
            else if(i>0 && j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<4; i++){
        for(int j=1; j<n+1; j++){
            if(j >= arr[i-1]){
                dp[i][j] = max(dp[i][j-arr[i-1]]+1, dp[i-1][j]);    
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<4; i++){
    //     for(int j=0; j<n+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[3][n];
}

int main(){
    int n, a, b, c;
    cin >> n;
    int arr[n];
    cin >> arr[0] >> arr[1] >> arr[2];
    cout << cutribbon(n, arr);
}

/*
5 1 2 3
ans=5
*/

/*
5 5 3 2
ans=2
*/

/*
7 5 5 2
ans=2
*/