#include <iostream>
#include <queue>
using namespace std;

void bfs(int** edges, int n, int f, bool* visited){

    queue<int> q;
    q.push(f);
    visited[f] = true;
    int front;
    while(!q.empty()){
        front = q.front();
        cout << front << " ";
        q.pop();
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1){
                if(visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                    // cout << "pushed: " << i << " its visited info: " << visited[i] << " ";
                }
            }
        }
    }
    cout << endl;
}

void returnconnectedcomponents(int** edges, int n){
    bool* visited = new bool;
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(visited[i] == false){
            bfs(edges, n, i, visited);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    int f,s;
    for(int i=0; i<e; i++){
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    returnconnectedcomponents(edges, n);
}

/*
8
7
1 3
1 4
3 4
2 5
2 7
5 7
6 0
*/