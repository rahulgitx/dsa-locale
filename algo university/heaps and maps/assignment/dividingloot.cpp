#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;            // loot digit and the person i

vector<int> lootdivide(vector<int> v, int n, int m){

    vector<int> ans;
    priority_queue<pi, vector<pi>, greater<pi>> pq;    // will keep track of total sum kept by each person
    
    pair<int, int> p;
    // assigning 0s upcoming items to each available person
    for(int i=0; i<m; i++){
        p = {0, i+1};
        pq.push(p);
        // cout << i+1 << " ";
        // ans.push_back(i+1);

    }

    for(int i=0; i<n; i++){
        pair<int, int> top = pq.top();
        pq.pop();
        top.first += v[i];
        pq.push(top);
        
        ans.push_back(top.second);
 
    }
    return ans;


}

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<int> v;
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> ans = lootdivide(v,n,m);
    for(int i=0; i<v.size(); i++){
        cout << ans[i];
        if(i != v.size()-1){
            cout << " "; 
        }
    }
}