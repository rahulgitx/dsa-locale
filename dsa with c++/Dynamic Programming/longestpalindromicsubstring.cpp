#include <bits/stdc++.h>
using namespace std;

string longest(string s){
    // initialization
    int n = s.length();
    if (n == 1){
        return s;
    }
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
    }

    int maxval = 0;
    int first = 0, last = 0;

    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        if(i<n-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(maxval < 2){
                    maxval = 2;
                    first = i;
                    last = i+1;
                }   

            }
            else{
                dp[i][i+1] = 0;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=n-3; i>=0; i--){
        for(int j=i+2; j<n; j++){
            if(s[i] == s[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                if(maxval < j-i+1){
                    maxval = j-i+1;
                    first = i;
                    last = j;
                }                
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "maxval:  " << maxval << " first: " << first << " last: " << last << endl;
    string ans;
    for(int k=first; k<=last; k++){
        ans += s[k];
    }
    // cout << "ans: " << ans;
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longest(s);
}

/*
aacabdkacaa
*/

/*
aaaabbaa
*/