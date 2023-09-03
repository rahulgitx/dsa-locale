#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

bool help(bool turn, int alice, int zeros, int ones, vector<vector<vector<int>>>& dp){

    if(zeros == 0 && ones == 0){
        if(alice%2 == 0) return true;
        else return false;
    }

    if(dp[zeros][ones][alice] != -1) return dp[zeros][ones][alice];

    bool ans = false;
    if(turn){ // alice's turn
        if(zeros){
            zeros--;
            bool t = help(!turn, alice,  zeros, ones, dp);
            zeros++;
            ans = (t || ans);
        }
        if(ones){
            ones--;
            bool t = help(!turn, alice+1,  zeros, ones, dp);
            ones++;
            ans = (t || ans);
        }
        dp[zeros][ones][alice] = ans;
        return ans;
    }


    ans = true;
    if(zeros){
        zeros--;
        bool t = help(!turn, alice, zeros, ones, dp);
        zeros++;
        ans = (ans && t);
    }
    if(ones){
        ones--;
        bool t= help(!turn, alice, zeros, ones, dp);
        ones++;
        ans = (ans&& t);
    }
    dp[zeros][ones][alice] = ans;
    return ans;
    
}
bool func(vector<int>& v){
    int zeros =0, ones=0;
    for(int i:v){
        if(i) ones++;
        else zeros++;
    }
    vector<vector<vector<int>>> dp(zeros+1, vector<vector<int>>(ones+1, vector<int>(ones+1, -1)));
    return help(1, 0, zeros, ones, dp);
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            v.push_back(temp%2);
        }
        if(func(v)){ cout << "Alice" << endl; }
        else{ cout << "Bob" << endl; }
    }
}
/*
4
3
1 3 5
4
1 3 5 7
4
1 2 3 4
4
10 20 30 40
*/
/*
1
4
1 2 3 4
*/
/*
1
3
1 3 5
*/

/*
1
3
0 0 1
*/