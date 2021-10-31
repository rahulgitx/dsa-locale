#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class graph{
    unordered_map<T, list<T>> mp;
    public:
        void addedge(T n, T e){
            mp[n].push_back(e);
            mp[e].push_back(n);
        }

        void dfsprint(T n, unordered_map<T, bool> &visited){
            cout << n << " ";
            visited[n] = true;

            typename list<T>::iterator it;
            for(it=mp[n].begin(); it!=mp[n].end(); it++){
                if(!visited[*it]){
                    dfsprint(*it, visited);
                }
            }
        }

        void dfs(T source){
            unordered_map<T, bool> visited;

            dfsprint(source, visited);
        }
        
};

int main(){
    int n, e;
    cin >> n >> e;
    
    graph<int> g;

    int s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d;
        g.addedge(s,d);
    }

    g.dfs(0);
}

/*
6 6
0 1
0 3
1 2
2 3
3 4
4 5
*/