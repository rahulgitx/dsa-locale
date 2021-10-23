// writing a adjacency matrix with DFS  and BFS traversal.

#include <iostream>
#include <queue>
using namespace std;


void dfsprint(int n, int** adjmatrix, int sv, bool* visited){
    

    cout << sv << " ";
    visited[sv] = true;     // marked as visited

    for(int i=0; i<n; i++){
        if(adjmatrix[sv][i] == 1){
            if(visited[i] == true){
                continue;
            }
            dfsprint(n, adjmatrix, i, visited);
        }
    }


}
void DFS(int** adjmatrix, int n){
    // marking all the visited list as false
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(visited[i] == false){
            dfsprint(n, adjmatrix, i, visited);
        }
    }

    delete visited;
}



void bfsprint(int n, int** adjmatrix, int sv, bool* visited){
    
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    int front;
    while(!q.empty()){
        front = q.front();
        cout << front << " ";
        q.pop();
        for(int i=0; i<n; i++){
            if(visited[i] == true){
                continue;
            }
            if(adjmatrix[front][i] == 1){
                q.push(i);
                visited[i] = true;
            }
        }    

    }
}
void BFS(int** adjmatrix, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(visited[i] == false){
            bfsprint(n, adjmatrix, i, visited);
        }
    }
    delete visited;
}


int main(){
    int n, e;
    cin >> n >> e;
    int** adjmatr = new int*[n];
    
    // marking all the cells as 0 in the adjacent matrix
    for(int i=0; i<n; i++){
        adjmatr[i] = new int[n];
        for(int j=0; j<n; j++){
            adjmatr[i][j] = 0;
        }
    }

    // getting edges input
    int f, s;
    for (int i=0; i<e; i++){
        cin >> f >> s;
        adjmatr[f][s] = 1;
        adjmatr[s][f] = 1;
    }


    cout << "dfsprint: " << endl;
    DFS(adjmatr, n);
    cout << endl;

    cout << "bfs : " << endl; 
    BFS(adjmatr, n);
    cout << endl;

    delete adjmatr;
}


/*
8
9
0 5
0 4
4 3
5 6
3 6
3 2
3 1
2 1
6 7
*/

/*
7
5
0 2
0 3
2 3
1 4
5 6
*/