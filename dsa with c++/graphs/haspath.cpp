#include <iostream>
#include <queue>
using namespace std;

bool haspath(int** edges, int n, int f, int s){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    if(f == s){
        return true;
    }
    queue<int> q;
    q.push(f);
    int front;

    while(!q.empty()){
        
        front = q.front();
        q.pop();
        
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1){
                if(visited[i] == false){
                    if(i == s){
                        return true;
                    }
                    q.push(i);
                }
            }
        }
    }
    return false;
}

int main(){
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    int f, s;
    for(int i=0; i<e; i++){
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    
    cout << haspath(edges, n, 3, 8);
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