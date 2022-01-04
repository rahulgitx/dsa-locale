#include <bits/stdc++.h>
using namespace std;

int unboundedknap(int n, int w, int val[], int wt[]){
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[w+1];
        for(int j=0; j<w+1; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j ){
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}


int main(){
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin >> wt[i];
    }

    cout << unboundedknap(n, w, val, wt);
}

/*
4 8
1 4 5 7
1 3 4 5
*/