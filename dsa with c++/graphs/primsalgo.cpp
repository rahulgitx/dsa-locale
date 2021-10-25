#include <climits>
#include <iostream>
using namespace std;

int findminweight(int* weights, bool* visited, int n){
    int minvert = -2;
    for (int i=0; i<n; i++){
        if(!visited[i] && (minvert == -2 || weights[minvert] > weights[i]) ){
            minvert = i;
        }
    }
    return minvert;
}

void primsalgo(int** edges, int n, int e){
    bool* visited = new bool[n];           
    int* weights = new int[n];             
    int* parent = new int[n];               

    for(int i=0; i<n; i++){               // O(n)
        weights[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    weights[0] = -1;
    parent[0] = -1;
 
    // total complexity = O(n-1 x n+n)  => o(n^2)
    for(int i=0; i<n-1; i++){
        int minweight = findminweight(weights, visited, n);           // O(n)
        visited[minweight] = true;

        for(int j=0; j<n; j++){                                        // O(n)
            if(edges[minweight][j] > -1 && visited[j] == false){
                weights[j] = edges[minweight][j];
                parent[j] = minweight;
            }
        }
    }

    cout << "printing mst: " << endl;
    for(int i=1; i<n; i++){
        cout << parent[i] << " " << i << " " << weights[i] << endl;
    }

}

int main(){
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = -1;
        }
    }

    int w, s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d >> w;
        edges[s][d] = w;
    }

    primsalgo(edges, n, e);
}

/*
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5
*/
