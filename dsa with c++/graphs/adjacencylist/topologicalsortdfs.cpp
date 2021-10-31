#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class graphs{
    int n=0;
    map<T, list<pair<T, int>>> mp;
    public:
        graphs(int n){
            this->n = n;
        }

        void insertedges(T n, T e, int w){
            mp[n].push_back(make_pair(e,w));
        }

        void dfshelp(T n, unordered_map<T, bool> &visited, list<T> &l){
            visited[n] = true;
            cout << "n: " << n << endl;
            for(auto i : mp[n]){
                if(!visited[i.first]){
                    dfshelp(i.first, visited, l);
                }
            }

            l.push_front(n);
        }

        void dfs(){
            unordered_map<T, bool> visited;
            for(auto i : mp){
                visited[i.first] = false;
            }
            list<T> l;

            for(auto i:mp){
                if(!visited[i.first]){
                    cout << "i.first: " << i.first << endl;
                    dfshelp(i.first, visited, l);
                }
            }

            for(auto i:l){
                cout << i << " ";
            }
        }
        
};


int main(){
    int n, e;
    cin >> n >> e;

    graphs<char> g(5);
    
    char s,d;
    int w;
    for(int i=0; i<e; i++){
        cin >> s >> d >> w ;
        g.insertedges(s,d,w);
    }

    g.dfs();
}

/*
5 5
0 2 0
1 2 0
1 3 0
2 4 0
3 4 0
*/

/*
5 5
A C 0
B C 0
B D 0
D E 0
C E 0
*/