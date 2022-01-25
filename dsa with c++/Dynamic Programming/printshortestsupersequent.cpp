#include <bits/stdc++.h>
using namespace std;

string printscs(string &x, string &y){
    int m = x.length();
    int n = y.length();
    int** dp = new int*[m+1];
    for(int i=0; i<m+1; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    string output;
    int i=m, j=n;

    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            output.push_back(x[i-1]);
            i--; j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                output.push_back(x[i-1]);
                i--;
            }
            else{
                output.push_back(y[j-1]);
                j--;
            }
        }
    }

    while(i>0){
        output.push_back(x[i-1]);
        i--;
    }
    while (j>0){
        output.push_back(y[j-1]);
        j--;
    }

    string ans;
    for(int k=output.length()-1; k>=0; k--){
        ans.push_back(output[k]);
    }
    
    return ans;

}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);
    cout << printscs(x, y) << "ans";
}

/*
abcdaf
acbcf
ans=acbcdaf
*/

/*
abac
cab
ans=cabac
*/