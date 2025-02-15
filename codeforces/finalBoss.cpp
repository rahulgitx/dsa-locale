//https://codeforces.com/problemset/problem/1985/F

#include <bits/stdc++.h>
using namespace std;

#define p pair<long long, int>

void getMinTimeToDefeatBoss(int h, vector<int>& damage, vector<int>& cooldown){
    int n = damage.size();
    priority_queue<p, vector<p>, greater<p>> pq;

    for(int i=0; i<n; i++) {
        pq.push({cooldown[i]+1, i});
        h -= damage[i];
        if(h<0){
            cout << 1 << endl;
            return;
        }
    }

    // cout << "h:" << h << endl;
    long long time = 1;
    while(h > 0){
        pair<long long, int> pair = pq.top(); pq.pop();
        int index = pair.second;
        time = pair.first;
        h -= damage[index];
        // cout << "ind:" << index << " dmg:" << damage[index] << " time:" << time << " h:" << h << endl;
        long long newTime = time + (long long)cooldown[index];
        pq.push({newTime, index});
    }
    // time++;
    cout << time << endl;
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        int h, n;
        cin >> h >> n;
        vector<int> damage(n), cooldown(n);
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            damage[i] = temp;
        }
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            cooldown[i] = temp;
        }
        getMinTimeToDefeatBoss(h, damage, cooldown);
    }
}

/*
8
3 2
2 1
2 1
5 2
2 1
2 1
50 3
5 6 7
5 6 7
50 3
2 2 2
3 3 3
90000 2
200000 200000
1 1
100000 1
1
200000
6 7
3 2 3 2 3 1 2
6 5 9 5 10 7 7
21 6
1 1 1 1 1 1
5 5 8 10 7 6

*/