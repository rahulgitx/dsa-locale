/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
*/

#include <bits/stdc++.h>
using namespace std;

int count(int n){
    int** dp = new int*[6];
    for(int i=0; i<6; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            else if(i>0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<n+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=1; i<6; i++){
        for(int j=1; j<n+1; j++){
            dp[i][j] = dp[i][j-1]+dp[i-1][j];
        }
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<n+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[5][n];
}

int main(){
    int n;
    cin >> n;
    cout << count(n);
}