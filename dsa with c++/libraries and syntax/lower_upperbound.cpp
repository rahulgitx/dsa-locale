#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(34);
    v.push_back(56);

    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 5);  // returns a pointer
    cout << *it << endl;

    // if you want it to return the index of lower_bound no found
    int index = lower_bound(v.begin(), v.end(), 5) - v.begin();
    cout << index << endl;

    if(it == v.end()) cout << "NOt found";

    map<int, int> mp;
    // cout << mp[4] << "random" <<endl;
    auto a = mp.lower_bound(4);
    // if(a == mp.begin()) cout << "first"  << endl;
    cout << "a:" << a->first << endl;
    mp[1]++;
    mp[3]++;
    mp[5]++;
    mp[6]++;
    mp[7]++;
    mp[8]++;
    mp[9]++;

    // for(auto it:mp) cout << it.first << " ";

    map<int, int>::iterator iter = mp.lower_bound(1);
    if(iter == mp.begin()) cout << "before beginning" << endl;
    iter--; // to find the no just smaller than the given no
    cout << "lowerbound:" << iter->first << endl;
}