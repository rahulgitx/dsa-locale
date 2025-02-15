import java.util.*;

public class E{
    public static int n;

    public static void dijkstra(List<List<Long>>[] graph, int[] hasHorse, long[] minDistance){
        PriorityQueue<Long[]> pq = new PriorityQueue<>((a, b ) -> {
            if(a[0] > b[0]) return 1;
            return -1;
        });

        int[] visited = new int[n+1];
        int[] visitedOnHorse = new int[n+1];
        minDistance[1] = 0l;


        pq.add(new Long[]{0l, 1l, (long)hasHorse[1]});

        while(!pq.isEmpty()){
            Long[] top = pq.poll();
            int u = top[1].intValue();
            long s = top[0], onHorse = top[2];
            minDistance[u] = Math.min(minDistance[u], s);

            if(onHorse == 0 && visited[u] == 1) continue;
            if(onHorse == 1 && visitedOnHorse[u] == 1) continue;

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

    public static long dijkstra2(List<List<Long>>[] graph, int[] hasHorse, long[] minDistance1){
        PriorityQueue<Long[]> pq = new PriorityQueue<>((a, b ) -> {
            if(a[0] > b[0]) return 1;
            return -1;
        });

        long start = n;
        long res = Long.MAX_VALUE;
        int[] visited = new int[n+1];
        int[] visitedOnHorse = new int[n+1];
        long[] minDistance2 = new long[n+1];
        for(int i=0; i<n+1; i++) minDistance2[i] = Long.MAX_VALUE;
        minDistance2[n] = 0l;



        pq.add(new Long[]{0l, (long)n, (long)hasHorse[n]});

        while(!pq.isEmpty()){
            Long[] top = pq.poll();
            int u = top[1].intValue();
            long s = top[0], onHorse = top[2];
            minDistance2[u] = Math.min(minDistance2[u], s);

            res = Math.min(res, Math.max(minDistance1[u], minDistance2[u]));

            if(onHorse == 0 && visited[u] == 1) continue;
            if(onHorse == 1 && visitedOnHorse[u] == 1) continue;

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



        // System.out.println("after second dijkstra");
        // for(int i=1; i<minDistance2.length; i++){
        //     System.out.print(minDistance2[i] + " ");
        // }
        // System.out.println();

        return res;

    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t > 0){
            t--;
            
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int h = scanner.nextInt();
            int[] hasHorse = new int[n+1];

            E.n = n;

            for(int i=0; i<h; i++){
                int node = scanner.nextInt();
                hasHorse[node] = 1;
            }

            List<List<Long>>[] graph = new ArrayList[n+1];
            for(int i=1; i<=n; i++){
                graph[i] = new ArrayList<>();
            }
            for(int i=0; i<m; i++){
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                long s = scanner.nextLong();
                graph[u].add(Arrays.asList((long)v, s));
                graph[v].add(Arrays.asList((long)u, s));
            }
            
            long[] minDistance = new long[n+1];
            for(int i=0; i<n+1; i++){
                minDistance[i] = Long.MAX_VALUE;
            }

            dijkstra(graph, hasHorse, minDistance);

            // System.out.println("after first dijkstra");
            // for(int i=1; i<minDistance.length; i++){
            //     System.out.print(minDistance[i] + " ");
            // }
            // System.out.println();

            long res = dijkstra2(graph, hasHorse, minDistance);



            if(res == Long.MAX_VALUE) res = -1;
            System.out.println(res);
        }
    }
}