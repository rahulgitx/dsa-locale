#include <bits/stdc++.h>
using namespace std;

int totalpalind(string s){
    int n = s.length();
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
    }

    int count = 0;

    for(int i=0; i<n; i++){
        dp[i][i] = 1; count++;
        if(i<n-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1; count++;
            }
            else{
                dp[i][i+1] = 0;
            }
        }
    }

    for(int i=n-3; i>=0; i--){
        for(int j=i+2; j<n; j++){
            if(s[i] == s[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1; count++;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << totalpalind(s);
}