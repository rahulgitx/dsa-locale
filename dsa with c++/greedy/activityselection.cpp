#include <bits/stdc++.h>
using namespace std;

int maxactivity(vector<int> start, vector<int> end, int n){
    int count = 0;
    int prevlast = 0;
    multimap<int, int> mp;
    for(int i=0; i<n; i++){
        // mp[end[i]] = start[i];
        mp.insert({end[i], start[i]});
    }
    for(auto it : mp){
        if(it.second >= prevlast){
            count++;
            prevlast = it.first;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> start;
    vector<int> end;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        start.push_back(temp);
    }
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        end.push_back(temp);
    }
    cout << maxactivity(start, end, n);
}

/*
4
1 3 2 5
2 4 3 6
*/