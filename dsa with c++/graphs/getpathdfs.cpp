#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfssearch(int** edge, int n, int f, int s, vector<int>& v, bool* visited){
    int flag = 0;
    visited[f] = true;
    if(f == s){ 
        // cout << "match found! " << f << endl;
        return true;
    }
    else{
        for(int i=0; i<n; i++){
            if(edge[f][i] == 1){
                if(visited[i] == false){
                    if(dfssearch(edge, n, i, s, v, visited)){
                        v.push_back(i);
                        cout << "pushed i: " << i ;
                        cout << " returning true " << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

vector<int> getpathdfs(int** edge, int n, int f, int s){
    vector<int> v;

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    if(dfssearch(edge, n, f, s, v, visited)){
        v.push_back(f);
        reverse(v.begin(), v.end());
        return v;
    }
    else{
        v.push_back(-1);
        return v;
    }

}

int main(){
    int n, e;
    cin >> n >> e;


    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
            // cout << "edges: ";
        }
    }

    int f, s;
    for(int i=0; i<e; i++){
        cin >> f >> s; 
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<int> ans;
    ans = getpathdfs(edges, n, 4, 6);
    for(int i=0; i<ans.size(); i++){
        cout << ans.at(i) << " ";
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