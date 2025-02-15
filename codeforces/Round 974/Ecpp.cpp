#include <bits/stdc++.h>
using namespace std;

int n;

public static void dijkstra(List<List<Long>>[] graph, int[] hasHorse, long[] minDistance){
        PriorityQueue<Long[]> pq = new PriorityQueue<>((a, b ) -> {
            if(a[0] > b[0]) return 1;
            return -1;
        });

        PriorityQueue<long long[]> pq;

        int[] visited = new int[n+1];
        int[] visitedOnHorse = new int[n+1];
        minDistance[1] = 0l;


        pq.add(new Long[]{0l, 1l, (long)hasHorse[1]});

        while(!pq.isEmpty()){
            Long[] top = pq.poll();
            int u = top[1].intValue();
            long s = top[0], onHorse = top[2];
            minDistance[u] = Math.min(minDistance[u], s);

            if(onHorse == 0) visited[u] = 1;
            if(onHorse == 1) visitedOnHorse[u] = 1;

            for(int i=0; i<graph[u].size(); i++){
                int v = graph[u].get(i).get(0).intValue();
                long s2 = graph[u].get(i).get(1);
                if(onHorse == 1) s2 = s2/2;

                if(onHorse == 0 && visited[v] == 1) continue;
                if(onHorse == 1 && visitedOnHorse[v] == 1) continue;

                pq.add(new Long[]{s+s2, (long)v, onHorse|hasHorse[v]});
            }
        }

    }
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,h;
        cin >> n >> m >> h;

        ::n = n;

        int hasHorse[n+1];
        for(int i=0; i<h; i++){
            int temp;
            cin >> temp;
            hasHorse[temp]++;
        }

        vector<vector<long long>> graph[n+1];
        for(int i=0; i<m; i++){
            long long u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        long long minDistance[n+1];
        for(int i=0; i<n+1; i++) minDistance[i] = LLONG_MAX;

        dijkstra(graph, hasHorse, minDistance);


    }
}