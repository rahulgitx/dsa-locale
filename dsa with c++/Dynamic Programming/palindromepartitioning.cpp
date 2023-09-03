#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s, int i, int j){
    int l=0;
    for(int k=i; k<=j; k++){
        if(s[k] != s[j-l]){
            return false;
        }
        l++;
    }
    return true;
}

int helper(const string &arr, int i, int j, int** dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(ispalindrome(arr, i, j)){
        return 0;
    }

    // cout << "i: " << i << " j: " << j << ":: " ;
    int temp, minval = INT_MAX;
    for(int k=i; k<j; k++){
        // cout << "i: " << i << " j: " << j << " k: " << k << endl;
        temp = helper(arr,i,k, dp) + helper(arr, k+1, j, dp) + 1;
        // cout << " temp: " << temp ;
        minval = min(temp, minval);

    }
    dp[i][j] = minval;
    // cout << " dp" << i << j << ": " << dp[i][j] << endl;


    return dp[i][j];
}

int nopartition(string arr){
    int n = arr.length();
    
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i>=j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }



    int ans = helper(arr, 0, n-1, dp);

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return ans;

}

int main(){
    string arr;
    cin >> arr;
    // cout << ispalindrome(arr, 0, arr.length()-1);
    cout << endl << "ans: " << nopartition(arr);
}

/*
ababbbabbababa
ans=3
*/

/*
aaabba
ans=1
*/