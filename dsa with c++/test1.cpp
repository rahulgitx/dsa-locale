#include <bits/stdc++.h>
using namespace std;


int main(){
    // unordered_map<int, int> mp;
    // cout << "size: " << mp.size() << endl;
    // mp[1]++;
    // cout << mp[1] << endl;
    // mp.erase(1);
    // cout << mp[1] << endl;
    // if(mp.count(1) == 1) { cout << "present" << endl; }
    // if(mp.count(2) == 1) { cout << "pressent 2" << endl; }
    // cout << "size:" << mp.size() << endl ;

    unordered_set<int> st;
    st.insert(1);
    cout << st.size() << endl;
    st.erase(1);
    cout << st.size();
}