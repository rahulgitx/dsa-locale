    #include <bits/stdc++.h>
    using namespace std;


    void func(int n, int x, int y, int turn){
        int sum = (n*(n+1))/2;

        if((sum%(x+y) != 0)){
                    cout << "Case #" << turn << " IMPOSSIBLE" << endl;
                    return;
        }
        int v = sum/(x+y);
        int t = v*min(x,y);


        int** dp = new int*[n+1];
        for(int i=0; i<n+1; i++){
            dp[i] = new int[t+1];
            for(int j=0; j<t+1; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                else if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }




        for(int i=1; i<n+1; i++){
            for(int j=1; j<t+1; j++){
                if(i > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j-i] || dp[i-1][j];
                }
            }
        }

        for(int i=0; i<n+1; i++){
            for(int j=0; j<t+1; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        if(dp[n][t] == 1){
            cout << "Case #" << turn << " POSSIBLE" << endl;
            cout << v*x << endl << v*y << endl;
        }
        else{
            cout << "Case #" << turn << " IMPOSSIBLE" << endl;
        }
    }

    int main(){
        int t;
        cin >> t;
        for(int i=1; i<=t; i++){
            int n, x, y;
            cin >> n >> x >> y;
            func(n, x, y, i);
        }
    }