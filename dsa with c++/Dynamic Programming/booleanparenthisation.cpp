#include <bits/stdc++.h>
using namespace std;

unordered_map<bool,int> boolexp(string arr, int i, int j){
    unordered_map<bool, int> ans;
    if(i == j){ 
        if(arr[i] == 'T'){
            ans[true] = 1;
            ans[false] = 0;
            return ans;
        }
        else{
            ans[true] = 0;
            ans[false] = 1;
            return ans;
        }
    }
    if(i>j){
        ans[true] = 0;
        ans[false] = 0;
        return ans;
    }

    unordered_map<bool, int> left, right;
    int t=0, f=0;
    for(int k=i+1; k<j; k = k+2){
        // cout << "i: " << i << " j: " << j << " k: " << k << " " << endl;
        left = boolexp(arr, i, k-1);
        right = boolexp(arr, k+1, j);
        // cout << " Lfalse: " << left[false] << " Ltrue: " << left[true] << " Rflase: " << right[false] << " Rtrue: " << right[true] << endl;  
        if(arr[k] == '|'){
            t += ((left[true])*(right[true]+right[false])) + (left[false]*(right[true]));
            f += (left[false]*right[false]);
        }
        else if(arr[k] == '&'){
            t += (left[true]*right[true]);
            f += (left[true]*right[false])+(right[false]*(right[true]+right[false]));
        }
        else{
            t += left[true]*right[false];
            f += left[false]*right[true];
        }
    }
    // cout << endl <<  "t: " << t << " f: " << f << endl;
    ans[true] = t;
    ans[false] = f;
    return ans;


}

unordered_map<bool, long long int> helper(string arr, int i, int j, unordered_map<bool, long long int>** dp){
    if(dp[i][j][true] != -1 && dp[i][j][false] != -1){
        return dp[i][j];
    }
    unordered_map<bool, long long int> left, right;
    int mod = 1003;
    int t=0, f=0;
    for(int k=i+1; k<j; k = k+2){
        // cout << "i: " << i << " j: " << j << " k: " << k << " " << endl;
        left = helper(arr, i, k-1, dp);
        right = helper(arr, k+1, j, dp);
        // cout << " Lfalse: " << left[false] << " Ltrue: " << left[true] << " Rflase: " << right[false] << " Rtrue: " << right[true] << endl;  
        // cout << "arr[k]: " << arr[k] << endl;
        if(arr[k] == '|'){
            t += (left[true]*right[true] + left[true]*right[false] + left[false]*right[true])%mod;
            f += (left[false]*right[false])%mod ;
        }
        else if(arr[k] == '&'){
            t +=  (left[true]*right[true])%mod;
            f += (left[true]*right[false] + left[false]*right[true] + left[false]*right[false])%mod;
        }
        else{
            t += (left[true]*right[false] + left[false]*right[true])%mod;
            f += (left[true]*right[true] + left[false]*right[false])%mod;
        }
    }
    // cout << "i: " << i << " j: " << j <<  " t: " << t << " f: " << f << endl << endl;
    dp[i][j][true] = t%mod;
    dp[i][j][false] = f%mod;
    return dp[i][j];
}

int countways(string arr, int n){
    unordered_map<bool, long long int>** dp = new unordered_map<bool,long long int>*[n];
    for(int i=0; i<n; i=i+2){
        dp[i] = new unordered_map<bool, long long int>[n];
        // if(i%2 == 0){
            for(int j=0; j<n; j=j+2){
                if(i == j){
                    if(arr[i] == 'T'){
                        dp[i][j][true] = 1;
                        dp[i][j][false] = 0;
                    }
                    else{
                        dp[i][j][true] = 0;
                        dp[i][j][false] = 1;
                    }
                }
                else if(i > j){
                    dp[i][j][true] = 0;
                    dp[i][j][false] = 0;
                }
                else{
                    dp[i][j][true] = -1;
                    dp[i][j][false] = -1;
                }
            }
        // }
    }

    // for(int i=0; i<n; i=i+2){
    //     for(int j=0; j<n; j=j+2){
    //         cout << dp[i][j][true]  << ":"<< dp[i][j][false] << " ";
    //     }
    //     cout << endl;
    // }


    unordered_map<bool, long long int> ans = helper(arr, 0, n-1, dp);
    // cout << "n: " << n << endl;
    return ans[true];
}

int main(){
    string s;
    cin >> s;
    unordered_map<bool, int> ans;
    cout << countways(s, s.length());
    // cout << ans[true];
}

/*
T|T&F^T
*/

/*
T^F|F
*/

/*
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F
*/