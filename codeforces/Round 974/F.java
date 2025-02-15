import java.util.*;

public class F{
    public long[] func(List<Integer>[] graph, long[] gold, int u, int parent, int c){
        long protectCurr = gold[u], notProtectCurr = 0;

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u].get(i);
            if(v == parent) continue;


            long[] child = func(graph, gold, v, u, c);
            long childTaken = child[0];
            long childNotTaken = child[1];

            protectCurr += Math.max(childTaken-(2*c), childNotTaken);
            notProtectCurr += Math.max(childTaken, childNotTaken);
        }

        // System.out.println("u: " + u  +  " gold[u]: " + gold[u] + " protectCurr: " + protectCurr + " notProtCurr: " + notProtectCurr);
        return new long[]{protectCurr, notProtectCurr};
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int c = scanner.nextInt();

            List<Integer>[] graph = new ArrayList[n+1];
            for(int i=1; i<=n; i++){
                graph[i] = new ArrayList<>();
            }


            long[] gold = new long[n+1];
            for(int i=1; i<=n; i++){
                gold[i] = scanner.nextInt();
            }

            for(int i=0; i<n-1; i++){
                int u = scanner.nextInt();
                int v = scanner.nextInt();

                graph[u].add(v); graph[v].add(u);
            }
            F obj = new F();
            long[] resPair = obj.func(graph, gold, 1, 0, c);
            long res = Math.max(resPair[0], resPair[1]);

            System.out.println(res);
        }
    }
    class Pair<T, K>{
        public T first;
        public K second;
        Pair(T t, K k){
            this.first = t;
            this.second = k;
        }
        T first(){
            return this.first;
        }
        K second(){
            return this.second;
        }
    }
}

/*
6
3 1
2 3 1
1 2
2 3
3 1
3 6 3
1 2
2 3
3 1
-2 -3 -1
1 2
2 3
6 1
5 -4 3 6 7 3
4 1
5 1
3 5
3 6
1 2
8 1
3 5 2 7 8 5 -3 -4
7 3
1 8
4 3
3 5
7 6
8 7
2 1
4 3
1 5 7 10
4 2
1 2
2 3
*/

/*
10
2 2
-5 -2
2 1
2 5
7 10
2 1
5 4
-1 -4 -5 3 9
4 3
5 4
3 1
4 2
4 3
1 5 7 10
4 2
1 2
2 3
8 1
3 5 2 7 8 5 -3 -4
7 3
1 8
4 3
3 5
7 6
8 7
2 1
2 2
-3 5
2 1
7 2
3 6 7 10 4 1 5
3 1
7 6
4 6
3 7
5 4
2 7
6 1
5 -4 3 6 7 3
4 1
5 1
3 5
3 6
1 2
1 3
-4
8 3
8 4 6 9 9 -5 -1 -2
5 7
4 8
4 3
8 6
3 1
5 2
5 3
5 5
6 1 1 3 5
5 2
4 1
5 4
3 2
8 1
0 5 7 10 0 -5 3 9
2 6
6 5
7 1
8 6
3 4
7 3
6 4
4 5
8 2 6 5
4 3
1 2
4 1
8 1
*/

/*
1
2 5
7 10
2 1
*/