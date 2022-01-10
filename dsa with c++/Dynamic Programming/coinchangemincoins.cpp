#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &coins, int amount){
    int n = coins.size();

    // initialization
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[amount+1];
        for(int j=0; j<amount+1; j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            else if(j > 0 && i == 0){
                dp[i][j] = INT_MIN;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(j >= coins[i-1]){
                if((dp[i][j-coins[i-1]]+1 >=0 && dp[i-1][j] >=0) || (dp[i][j-coins[i-1]]+1 < 0 && dp[i-1][j] < 0)){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                else{
                    dp[i][j] = max(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<amount+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if(dp[n][amount] < 0){
        return -1;
    }
    return dp[n][amount];

}

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        coins.push_back(temp);
    }

    cout << func(coins, amount);
}

/*
3 5
1 2 3
ans=2
*/

/*
1 3
2
*/