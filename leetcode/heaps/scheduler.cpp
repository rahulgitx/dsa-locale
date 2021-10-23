#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
        
    unordered_map<char, int> mp;
    for (int i=0; i<tasks.size(); i++){
        mp[tasks[i]]++;
    }
    
    
    unordered_map<char,int>::iterator it;
    priority_queue<pair<int, char>> pq;
    for(it=mp.begin(); it!=mp.end(); it++){
        pq.push({it->second,it->first});
    }
    // cout << "pq.size(): " << pq.size() << endl;
    vector<char> ansv;
    pair<int, char> top;
    
    while(!pq.empty()){
        vector<pair<int, char>> temp;
        int j=0;
        while(!pq.empty()){                         // inserting top n+1 elements into a temporary array
            temp.push_back(pq.top());
            pq.pop();
            if(j == n){
                break;
            }
            j++;
        }
        
        for(int i=0; i<temp.size(); i++){           // inserting those elements into a answer array and decrementing characters count
            // cout << temp[i].second << " ";
            ansv.push_back(temp[i].second);
            temp[i].first--;
        }
        // cout << endl;
        if(temp.size()<n+1){                         //  if the elements are less than required then * is pushed
            int rest = n+1-temp.size();
            for(int j=0; j<rest; j++){
                ansv.push_back('*');
            }
        }
        for(int i=0; i<temp.size(); i++){               // pushing characters with decremented count back into heap
            if(temp[i].first > 0){
                pq.push(temp[i]);
            }
        }
    }
    for (int i=ansv.size()-1; i>0; i--){
        if(ansv[i] == '*'){
            ansv.pop_back();
        }
        else{
            break;
        }
    }
    return ansv.size();
}

int main(){
    char c[] = {'A','A','A','B','B','B'};
    vector<char> v;
    for (int i=0; i<6; i++){
        v.push_back(c[i]);
    }

    int n=2;
    int output = leastInterval(v, n);
    cout << output;


}