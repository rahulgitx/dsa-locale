#include <iostream>
#include <queue>
using namespace std;

bool isconnected(int** edges, int n, int f){
    queue<int> q;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    q.push(f);
    int front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        visited[front] = true;
        for(int i=0; i<n; i++){
            if(edges[front][i]){
                if(visited[i] == false){
                    q.push(i);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            return false;
        }
    }
    return true;
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

    cout << isconnected(edges, n, 0);
}