#include <iostream>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

template<typename T>
class graph{
    int n;
    unordered_map<T, list<pair<T, int>> > mp;
    public:
        graph(int n){
            this->n = n;
        }
        void insertedges(T n, T e, int w){
            mp[n].push_back(make_pair(e,w));
            mp[e].push_back(make_pair(n,w));
        }

        int findmin(unordered_map<T, bool> &visited, unordered_map<T, int> weights){
            int flag = 0;
            T minvert;
            typename unordered_map<T, int>::iterator it;
            for(it=weights.begin(); it!=weights.end(); it++){
                if(!visited[it->first] && (flag == 0 || weights[minvert] > it->second)){
                    cout << it->first << " : " << it->second << endl;
                    minvert = it->first;
                    flag = 1;
                }
            }
            return minvert;
        }

        void primsalgo(){
            unordered_map<T, bool> visited;
            unordered_map<T, T> parent;
            unordered_map<T, int> weights;
            typename unordered_map<T, list<pair<T, int> >>::iterator it;
            for(it=mp.begin(); it!=mp.end(); it++){
                weights[it->first] = INT_MAX;
                visited[it->first] = false; 
            }

            T start = mp.begin()->first;
            cout << "start: " << start << endl;
            weights[start] = 0;
            parent[start] = -1;

            typename list<pair<T, int>>::iterator itlist;
            for(int i=0; i<n-1; i++){
                T minvert = findmin(visited, weights);
                cout << "minvert: " << minvert << endl;
                visited[minvert] = true;

                for(itlist=mp[minvert].begin(); itlist!=mp[minvert].end(); itlist++){
                    if(!visited[itlist->first]){
                        weights[itlist->first] = itlist->second;
                        parent[itlist->first] = minvert;
                    }
                }
            }

            typename unordered_map<T, T>::iterator itp;
            for(itp=parent.begin(); itp!=parent.end(); itp++){
                cout << itp->first << " : " << itp->second << endl;
            }

            

        }
};

int main(){
    int n, e;
    cin >> n >> e;

    graph<int> g(n);

    int s, d, w;
    for(int i=0; i<e; i++){
        cin >> s >> d >> w;
        g.insertedges(s, d, w);
    }

    g.primsalgo();
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
