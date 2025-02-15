#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

// int getLowerBound(set<int> st, int k){
//     set<int>::iterator it, low, high, mid;
//     low = st.begin(); high = st.end();
//     high--;
//     while(low <= high){
//         mid = 
//     }
// }


int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1,2});
    pq.push({1,1});
    pq.push({3,4});
    while(pq.size()){
        cout << pq.top().first << "," << pq.top().second << endl;
        pq.pop();
    }

    int n = 3;
    int at[3]={1,2,3};
    int dt[3] = {1,2,3};
    vector<vector<int>> timeSlab(n);
    for(int i=0; i<n; i++){
        vector<int> v = {at[i], dt[i]};
        timeSlab[i] = v;  
    }
}

/*
6
5 -9 10 -8 -2 -1
*/

/*
6
1 3 50
1 2 60
1 2 40
2 4 10
3 5 40
3 6 70
*/

/*
6
1 2 3 4 -1 -2
10
*/

/*
14
1 0 1 4 3 2 4 -1 -4 -5 3 5 60 6
2
*/