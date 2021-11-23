#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> range(int i, vector<int> &nums){
    unordered_map<int, int> mp;
    for(int j = i+1; j <= i+nums[i]; j++){
        // r.push_back(j+nums[j]);
        mp[j] = j+nums[j];
    }
    return mp;
}
int maxim(unordered_map<int, int> range){
    int maxval = range.begin()->second;
    int maxindex = range.begin()->first;
    for(auto it : range){
        if(maxval < it.second){
            maxval = it.second;
            maxindex = it.first;
        }
    }
    return maxindex;
}
int jump(vector<int>& nums) {
    int curr = 0;
    int jumps = 0;
    while(curr < nums.size()-1){
        curr = maxim(range(curr, nums));
        jumps++;
    }
    return jumps;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    cout << jump(v);
}

/*
5
2 3 1 1 4
*/