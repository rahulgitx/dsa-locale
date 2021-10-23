#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int countsoldiers(vector<int> v){ 

    unordered_map<int, int> mp;                // mapping
    for (int i=0; i<v.size(); i++){
        mp[v[i]]++;
    }

    priority_queue<pi> pq;                    // get into a max heap
    unordered_map<int, int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        pq.push(make_pair(it->second, it->first));
    }

    pair<int, int> top = pq.top();               // deciding the number of elements to be in the middle of maximum repeating number
    int max = top.first;
    int midnumber = ceil((max-1)/(v.size()-max));
   
    vector<int> arrangedv;
    while(!pq.empty()){

        vector<pair<int, int>> temp;
        for(int i=0; i<midnumber+1 && !pq.empty(); i++){     // inserting most frequent + rest midumber elements into a vector temp
            temp.push_back(pq.top());
            pq.pop();
        }

        for(int i=0; i<temp.size(); i++){            //  from temp inserting the popped elements into arragnedv and reducing their count
            arrangedv.push_back(temp[i].second);
            temp[i].first--;
        }

        for(int i=0; i<temp.size(); i++){     // pushing them back in if their count hasn't been turned to 0
            if(temp[i].first > 0){
                pq.push(temp[i]);
            }
        }
    }

    int count = 0;
    int last = arrangedv[arrangedv.size()-1];
    for(int i=arrangedv.size()-2; i>=0; i--){      // counting the pairs left in the end
        if(last == arrangedv[i]){
            count++;
            last = arrangedv[i-1];
            i--;
        }
        else{
            break;
        }
    }
    return count; 
}  



int main(){
    int n;
    cin >> n;
    int temp;
    vector<int> v;
    for (int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int output = countsoldiers(v);
    cout << output;
}


