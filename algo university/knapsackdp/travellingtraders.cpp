#include <bits/stdc++.h>
using namespace std;

pair<int, int> knapsackmod(int w, int n, int wt[], int p[]){
    pair<int, int>** dp = new pair<int, int>*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new pair<int, int>[w+1];
        for(int j=0; j<w+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = {0, 0};
            }
            else{
                dp[i][j] = {-1, -1};
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<w+1; j++){
    //         pair<int, int> output = dp[i][j];
    //         cout << output.first << ":" << output.second << " "; 
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j){
                pair<int, int> temp1 = dp[i-1][j-wt[i-1]];
                pair<int, int> temp2 = dp[i-1][j];
                // cout << "p: " << p[i-1];
                temp1.first += p[i-1];
                temp1.second += wt[i-1];
                // temp2.second += wt[i-1];

                if(temp1.first > temp2.first){
                    // cout << " f " ;
                    dp[i][j] = temp1;
                }
                else{
                    // cout << " s ";
                    dp[i][j] = temp2;
                }
            }
            else{
                // cout << "w[t]: " << wt[i-1] << " j " ;
                // cout << " th ";
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            pair<int, int> output = dp[i][j];
            cout << output.first << ":" << output.second << " "; 
        }
        cout << endl;
    }

    return dp[n][w];
}

int main(){
    // int n, w1, w2, c;
    // cin >> n >> w1 >> w2 >> c;
    // vector<int> pos, neg;
    // int temp;
    // for(int i=0; i<n; i++){
    //     cin >> temp;
    //     if(temp > 0){
    //         pos.push_back(temp);
    //     }
    //     else{
    //         neg.push_back(temp);
    //     }
    // }
    int n, w;
    cin >> n >> w;
    int values[n], weights[n];
    for(int i=0; i<n; i++){
        cin >> values[i];
    }
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    pair<int, int> ans;
    ans = knapsackmod(w, n, weights, values);
    cout << "profit: " << ans.first << " weights: " << ans.second;

}
/*
5 30
1 5 10 20 15
5 10 20 5 20
ans=36
*/
/*
3 4
1 2 3
4 5 1
ans=3
*/
/*
3 4
1 2 3
1 5 1
ans=4
*/

