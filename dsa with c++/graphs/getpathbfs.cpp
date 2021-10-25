#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> getpathbfs(int** edges, int n, int f, int s){
    vector<int> v;
    if(f == s){
        v.push_back(f);
        return v;
    }
    int* visited = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    unordered_map<int, int> mp;
    queue<int> q;
    q.push(f);
    visited[f] = true;
    int front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1){
                if(visited[i] == false){
                    mp[i] = front;
                    cout << "i: " << i << " mp[i]: " << mp[i] << endl;

                    if (i == s){
                        cout << "found";
                        v.push_back(i);
                        while(mp.count(i)>0){
                            v.push_back(mp[i]);
                            // cout << "i: " << i << " mp[i]: " << mp[i] << endl;
                            i = mp[i];
                        }       
                        break;   
                    }

                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    if(v.empty()){
        v.push_back(-1);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(){
    int n, e;
    cin >> n >> e;
    
    int** edges = new int*[n];

    int f, s;
    for (int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<int> v;
    v = getpathbfs(edges, n, 0, 4);
    for(int i=0; i<v.size(); i++){
        cout << v.at(i) << " ";
    }
}

/*
7
7
0 1
0 3
1 2
3 2
3 4
2 5
5 6
*/

/*
5
3
0 1
0 2
3 4
*/