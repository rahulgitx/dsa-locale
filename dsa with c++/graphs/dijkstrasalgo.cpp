#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int minofweights(int* weights, bool* visited, int n){
    int minvertex = -1;
    for(int i=0; i<n; i++){
        if(visited[i] == false && (minvertex == -1 || weights[minvertex] > weights[i]) ){
            minvertex = i;
        }
    }
    return minvertex;
}

void djikstrasalgo(int** edges, int n, int e, int start){
    bool* visited = new bool[n];
    int* weights = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weights[i] = INT_MAX; 
    }

    unordered_map<int, int> mp;
    weights[start] = 0;
    int current ;

    for(int i=0; i<n; i++){
        current = minofweights(weights, visited, n);
        cout << "current: " << current << endl;
        visited[current] = true;

        for(int j=0; j<n; j++){
            if(edges[current][j] != -1 && visited[j] == false){
                cout << " weights: " << current<< "+ edges " << current <<"&" <<  j << ": " << weights[current] + edges[current][j] << endl;
                if( (weights[current] + edges[current][j]) < weights[j]){
                    weights[j] = weights[current] + edges[current][j];
                }
            }
        }
        
    }

    for(int i=0; i<n; i++){
        cout << i << " " << weights[i] << endl;
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0; i<e; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = -1;
        }
    }

    int w, s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    djikstrasalgo(edges, n, e, 0);
}

/*
6 11
0 1 5
0 4 10
0 2 1
1 2 2
1 4 3
2 4 8
2 3 9
2 5 1
4 5 6
3 5 4
4 3 7
*/