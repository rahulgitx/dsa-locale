// kruskal's algorithm using union find method for cycle detection.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


class Edge{
    public:
        int weight;
        int source;
        int destination;
};

bool myf(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findparent(int e, int* parent){
    if(parent[e] == e){
        return e;
    }
    else{
        return findparent(parent[e], parent);
    }
}

void kruskalsalgo(Edge* edges, int n, int e){
    sort(edges, edges+e, myf);  // firstly sorted our edges w.r.t the weights         O(eloge)

    int* parent = new int[n];   // creating the parent array for all the nodes and initialising them with themselves  O(n)
    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    Edge* mstedges = new Edge[n-1];  // creating the array that will contain the mst edges         O(n-1)

    int count = 0;
    for(int i=0; i<e; i++){

        int sourceparent = findparent(edges[i].source, parent);
        int destinationparent = findparent(edges[i].destination, parent);

        if(sourceparent != destinationparent){
             
            mstedges[count].destination = edges[i].destination;
            mstedges[count].source = edges[i].source;
            mstedges[count].weight = edges[i].weight;
        
            parent[edges[i].destination] = parent[edges[i].source];
            count++;
        }
    }

    //printing ans
    cout << endl;
    for(int i=0; i<n-1; i++){
        cout << mstedges[i].source << " " << mstedges[i].destination << " " << mstedges[i].weight << endl;
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    Edge* edges = new Edge[e];
    // Edge edge[e];
    int w, s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d >> w;
        edges[i].destination = d;
        edges[i].source = s;
        edges[i].weight = w;
    }

    kruskalsalgo(edges, n, e);
}

/*
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8
4 5 2
2 5 9
3 5 6
*/
 
 /*
6 11
0 1 2
1 3 1
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6
*/