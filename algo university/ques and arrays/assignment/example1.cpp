#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    vector<int> queries;
    int i=0;
    while(i<q){
        int temp; 
        cin >> temp;
        queries.push_back(temp);
        if (temp == 1){
            int tile;
            cin >> tile;
            queries.push_back(tile);
        }
        i++;
    }

    i = 0;
    stack<int> s;
    stack<int> highest;
    while(i<queries.size()){
        if (queries[i] == 0){
            if(s.top() == highest.top()){
                highest.pop();
            }
            s.pop();
        }
        else if (queries[i] == 1){
            i++;
            s.push(queries[i]);
            if (highest.empty() || queries[i] >= highest.top()){
                highest.push(queries[i]);
            }
        }
        else if( queries[i] == 2){
            cout << highest.top() << endl;
        }
        i++;
    }
    
}