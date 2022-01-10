// cut the given rod into such pieces so as to get maximum profit. Given the price for rod for each length of piece.
#include <bits/stdc++.h>
using namespace std;

int cutrod(int price[], int n){
    int L = n;
    int len[n];
    for(int i=1; i<=n; i++){
        len[i-1] = i;
    }

    //initialisation
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(j >= len[i-1]){
                dp[i][j] = max(dp[i][j-len[i-1]]+price[i-1], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<n+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][n];
}

int main(){
    int n; 
    cin >> n;
    int price[n];
    for(int i=0; i<n; i++){
        cin >> price[i];
    }

    cout << cutrod(price, n);

}

/*
8
1 5 8 9 10 17 17 20
ans=22
*/
