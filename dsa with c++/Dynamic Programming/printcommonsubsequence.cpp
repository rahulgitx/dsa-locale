#include <bits/stdc++.h>
using namespace std;

string printlongest(string &x, string &y, int n, int m){
    string** dp = new string*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new string[m+1];
        for(int j=0; j<m+1; j++){
            dp[i][j] = "";
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + x[i-1];
            }
            else{
                if(dp[i-1][j].length() >= dp[i][j-1].length()){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << dp[i][j] << " "; 
        }
        cout << endl;
    }
    return dp[n][m];
}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);
    cout << printlongest(x,y,x.length(), y.length());
}

/*
ABCD
BACDBDCD
ans=ABCD
*/

/*
abcde
ace
ans=ace
*/

/*
abc
abc
ans=abc
*/

/*
abc
def
ans=
*/