#include <bits/stdc++.h>
using namespace std;

vector<long long> func(vector<int> graph[], int gold[], int u, int parent, int c){
        long long protectCurr = gold[u], notProtectCurr = 0;

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if(v == parent) continue;


            vector<long long> child = func(graph, gold, v, u, c);
            long long childTaken = child[0];
            long long childNotTaken = child[1];

            protectCurr += max(childTaken-(2*c), childNotTaken);
            notProtectCurr += max(childTaken, childNotTaken);
        }

        // System.out.println("u: " + u  +  " gold[u]: " + gold[u] + " protectCurr: " + protectCurr + " notProtCurr: " + notProtectCurr);
        return {protectCurr, notProtectCurr};
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;

        int gold[n+1];
        for(int i=1; i<=n; i++){
            cin >> gold[i];
        }

        vector<int> graph[n+1];
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<long long> resVect = func(graph, gold, 1, 0, c);
        cout << max(resVect[0], resVect[1]) << endl;
    }
}