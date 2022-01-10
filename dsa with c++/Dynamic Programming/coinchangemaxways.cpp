#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins){
    //initialisation
    int n = coins.size();
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[amount+1];
        for(int j=0; j<amount+1; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i==0 && j>0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

        // for(int i=0; i<n+1; i++){
        //     for(int j=0; j<amount+1; j++){
        //         cout << dp[i][j] << " ";
        //     }
        // cout << endl;
        // }
        // cout << endl << endl;


    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(j >= coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<amount+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

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
    // for(int i=0; i<coins.size(); i++){
    //     cout << coins[i] << " ";
    // }
    cout << endl;
    cout << "ans: " << change(amount, coins);
}

/*
3 5
1 2 3
ans=5
*/