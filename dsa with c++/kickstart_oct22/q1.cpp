#include <bits/stdc++.h>
using namespace std;


void func(vector<int>& v, vector<int>& john, int c){
        int ans = 0;
        for(int i=0; i<john.size(); i++){
            if(john[i] < v[i]){
                ans += v[i]-john[i];
            }
        }
        cout << "Case #" <<c << ": " << ans << endl;
        
}

int main(){
    
    int t;
    cin >> t;
    int c = 1;
    while(c <= t){
        int m, n, p;
        cin >> m >> n >> p;
        vector<int> v(n, INT_MIN);
        vector<int> john;
        // cout << m << n << p;
        // for(int i=1; i<=m; i++){
        //     for(int j=0; j<n; j++){
        //         int t;
        //         cin >> t;
        //         // cout << t << " ";
        //         if(i == p){
        //             john.push_back(t);
        //         }
        //         v[j] = max(v[j], t);
        //         // cout << "last";
        //     }
        //     // cout << "outside";
        // }
        // func(v, john, c);
        // c++;
        cout << c << " ";
        c++;

    }
    return 0;
}