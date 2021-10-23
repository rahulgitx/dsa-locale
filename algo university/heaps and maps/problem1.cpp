// return k most frequent elements 

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;


void kfrequent(vector<int> v, int k){
    
    // mapping
    unordered_map<int, int> mymap;
    for (int i=0; i<v.size(); i++){
        if(mymap.count(v[i]) > 0){
            mymap[v[i]] += 1;
        }
        else{
            mymap[v[i]] = 1;
        }
    }

    unordered_map<int, int>::iterator it = mymap.begin();
    // vector<pair<int,int>> heapv;
    // for(it = mymap.begin(); it!=mymap.end(); it++){
    //     heapv.push_back({it->first, it->second});
    // }

    it = mymap.begin();

    // cout << "pushing first k element pairs in the queue" << endl;
    priority_queue<  pi, vector<pi>, greater<pi> > pq;
    for (int i=0; i<k; i++){
        pq.push(make_pair(it->second, it->first));      // ordered by element at first place  it->second is the frequency by which we want it to be sorted
        it++;
    }

    // cout << "keeping a pair of k most frequent elments" << endl;
    for(int i=k; i<mymap.size(); i++){
        pair<int, int> top = pq.top();
        if(top.first < it->second){
            pq.pop();
            pq.push(make_pair(it->second, it->first));
            it++;
        }
        
    }

    // popping out the output
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        cout << top.second << ": " << top.first << endl;
        pq.pop();
    }
}

int main(){
    int k=3;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);

    kfrequent(v, k);
}