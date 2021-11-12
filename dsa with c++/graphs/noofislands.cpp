#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
    
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void dfsrun(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j){
    // cout << "inside dfsrun of i: " << i << " j: " << j << endl;
    visited[i][j] = true;
    if(i-1>=0 && grid[i-1][j] == '1' && visited[i-1][j] == false){    // top
        dfsrun(grid, visited, i-1, j);
    }
    if(j+1 <= grid[0].size()-1 && grid[i][j+1] == '1' && visited[i][j+1] == false){    // right
        dfsrun(grid, visited, i, j+1);
    }
    if(i+1 <= grid.size()-1 && grid[i+1][j] == '1' && visited[i+1][j] == false){    // bottom
        dfsrun(grid, visited, i+1, j);            
    }
    if(j-1 >=0 && grid[i][j-1] == '1' && visited[i][j-1] == false){    // left
        dfsrun(grid, visited, i, j-1);
    }
}


int numIslands(vector<vector<char>>& grid) {
    
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size()));
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            visited[i][j] = false;
        }
    }
    
    int noi = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(visited[i][j] == false && grid[i][j] == '1'){
                dfsrun(grid, visited, i, j);
                noi++;
                // cout << " noi: " << noi << endl;
            }
        }
    }
    return noi;
}
    

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m));
    char temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            grid[i][j] = temp; 
        }       
    }
    // cout << grid[-1][0] << endl;
    cout << numIslands(grid);


    // cout << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

/* 
4 5
1 1 0 0 0
1 1 0 0 0 
0 0 1 0 0 
0 0 0 1 1
*/