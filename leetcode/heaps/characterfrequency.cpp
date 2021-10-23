#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char, int> mymap;
        for(int i=0; i<s.length(); i++){
            // if(mymap.count(s[i])>0){
                mymap[s[i]] += 1;
            // }
            // else{
            //     mymap[s[i]] = 1;
            // }
        }
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int>::iterator it;
        for(it=mymap.begin(); it!=mymap.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        pair<int, char> top;
        string ans = "";
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            for(int i=0; i<top.first; i++){
                ans += top.second;
            }
        }
        return ans;
    }

int main(){
    string s;
    getline(cin, s);
    string ans = frequencySort(s);
    cout << "getting output" << endl << ans;
}