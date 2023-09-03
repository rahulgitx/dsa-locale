#include <bits/stdc++.h>
using namespace std;

int findmax(string s){
        //initialization
        int n = s.length();
        int** dp = new int*[n+1];
        for(int i=0; i<n+1; i++){
            dp[i] = new int[n+1];
        }
        for(int i=0; i<n+1; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        string x = s;
        string y = s;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(x[i-1] != y[j-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else{
                    if(i == j){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                    else{
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                }
            }
        }

        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return dp[n][n];
}

int main(){
    string s;
    cin >> s;
    cout << findmax(s);
}


