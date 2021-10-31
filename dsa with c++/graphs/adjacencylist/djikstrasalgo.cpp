#include <iostream>
#include <climits>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph{
    
    int n;
    unordered_map<T, list<pair<T,int>>> mp;

    public:

        graph(int n){
            this->n = n;
        }

        void insertedge(T n, T e, int w, bool directed){
            mp[n].push_back(make_pair(e,w));
            if(directed){
                mp[e].push_back(make_pair(n,w));
            }
        }

        T getmin(unordered_map<T, int> weights, unordered_map<T, bool> &visited, int n){
            int flag = 0;
            T minvert;
            typename unordered_map<T, int>::iterator it;
            for(it=weights.begin(); it!=weights.end(); it++){
                // cout << "visited: " << visited[minvert] << endl;
                // cout << it->first << ": " << it->second << endl;
                if(visited[it->first] == false){
                    if((flag == 0 || it->second < weights[minvert]) ){
                        minvert = it->first;
                        flag = 1;
                        // cout << "current minvert: " << minvert << endl;
                        
                    }
                }
            }
                            // cout << "mivert: " << minvert << endl;
            return minvert;
        }

        void primsalgo(T s){

            unordered_map<T, bool> visited;
            unordered_map<T, int> weights;
            typename unordered_multimap<T, list<pair<T,int>>>::iterator it;
            for(it=mp.begin(); it!=mp.end(); it++){
                weights[it->first] = INT_MAX; 
            }
            
            T start = s;
            // cout << "start: " << start << endl;
            weights[start] = 0;
            typename list<pair<T,int>>::iterator itlist;
            
            for(int i=0; i<n-1; i++){
                T minvert = getmin(weights,visited,n);

                visited[minvert] = true;
                // cout << minvert << ": ";
                for(itlist=mp[minvert].begin(); itlist!=mp[minvert].end(); itlist++){
                 
                    if(!visited[itlist->first]){
                        // cout << itlist->first << " ";
                        if(weights[itlist->first] > itlist->second + weights[minvert]){
                            // cout << "->" << itlist->second + weights[minvert] << " ";
                            weights[itlist->first] = itlist->second + weights[minvert];
                        }
                    }
                }
                                        // cout << endl;
            }

            typename unordered_map<T, int>::iterator itw;
            for(itw=weights.begin(); itw!=weights.end(); itw++){
                cout << itw->first << " : " << itw->second << endl;
            }

        }

};

int main(){
    int n, e;
    cin >> n >> e;

    bool directed;
    int s, d, w;
    graph<int> g(n);
    for(int i=0; i<e; i++){
        cin >> s >> d >> w >> directed;
        g.insertedge(s,d,w,directed);
    }

    g.primsalgo(0);

}


/*
5 7
0 1 4 1
0 2 8 1
1 3 6 1
1 2 2 1
2 3 3 1
2 4 9 1
3 4 4 1
*/