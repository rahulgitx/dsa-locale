#include <bits/stdc++.h>
using namespace std;

long long int maxprod(int cost[], int cars[], int n, int c){
    //initialization
    long long int** dp = new long long int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new long long int[c+1];
        for(int j=0; j<c+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    // cout << "cars: " ;
    // for(int i=0; i<n; i++){
    //     cout << cars[i] << " ";
    // }
    // cout << endl << "costs: " ;
    // for(int i=0; i<n; i++){
    //     cout << cost[i] << " ";
    // }
    // cout << endl;


    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<c+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<c+1; j++){
            if(cost[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-cost[i-1]] + cars[i-1], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<c+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    return dp[n][c];
}

int main(){
    int n, c;
    cin >> n >> c;
    int cost[n], cars[n];
    for(int i=0; i<n; i++){
        cin >> cost[i] >> cars[i];
    }

    cout  << maxprod(cost, cars, n, c);
}