#include <bits/stdc++.h>
using namespace std;

// int dp[40][1001][1001][100][100];
// memset(dp, 0, sizeof(dp));

int helper(int v1, int w1, int v2, int w2, int i, int w[], int v[], unordered_map<string, int> dp){
    string istring = to_string(i), v1string = to_string(v1), v2string = to_string(v2);
    string w1string = to_string(w1), w2string = to_string(w2);
    string key = istring+"_"+v1string+"_"+v2string+"_"+w1string+"_"+w2string;
    if(dp.count(key) > 0){
        return dp[key];
    }
    if(i == 0){
        if(w1 > w2){
            dp[key] = w1-w2;
            return dp[key];
        }
        else{
            dp[key] = w2-w1;
            return dp[key];
        }
    }
    if(v1 == 0 && v2 == 0){
        return -1;
    }

    if(v[i-1] <= v1 && v[i-1] <=v2){
        dp[key] = min(helper(v1-v[i-1], w1+w[i-1], v2, w2, i-1, w, v, dp), 
                    helper(v1, w1, v2-v[i-1], w2+w[i-1], i-1, w, v, dp));
    }
    else if(v[i-1] <= v1){
        dp[key] = helper(v1-v[i-1], w1+w[i-1], v2, w2, i-1, w, v, dp);
    }
    else if(v[i-1] <= v2){
        dp[key] = helper(v1, w1, v2-v[i-1], w2+w[i-1], i-1, w, v, dp);
    }
    else{
        dp[key] = -1;
    }

    return dp[key];
}

int memo(int v1, int w1, int v2, int w2, int n, int w[], int v[]){

    unordered_map<pair<string, int> dp;
    
    return helper(v1, w1, v2, w2, n, w, v, dp);
}

int solve(int v1, int w1, int v2, int w2, int i, int w[], int v[]){
    if(i == 0){
        if(w1 > w2){
            return w1-w2;
        }
        else{
            return w2-w1;
        }
    }
    if(v1 == 0 && v2 == 0){
        return -1;
    }

    if(v[i-1] <= v1 && v[i-1] <=v2){
        return min(solve(v1-v[i-1], w1+w[i-1], v2, w2, i-1, w, v), 
                    solve(v1, w1, v2-v[i-1], w2+w[i-1], i-1, w, v));
    }
    else if(v[i-1] <= v1){
        return solve(v1-v[i-1], w1+w[i-1], v2, w2, i-1, w, v);
    }
    else if(v[i-1] <= v2){
        return solve(v1, w1, v2-v[i-1], w2+w[i-1], i-1, w, v);
    }
    else{
        return -1;
    }
}

int main(){
    int n, V;
    cin >> n >> V;
    int w[n], v[n];
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    int v1 = V, v2 = V;
    int w1 = 0, w2 = 0;
    cout  << memo(v1, w2, v2, w2, n, w, v);
}

/*
5 10
16 2
19 2
16 3
15 3
19 4
ans = 9
*/

/*
5 10
16 2
19 6
16 3
15 3
19 6
ans=-1
*/