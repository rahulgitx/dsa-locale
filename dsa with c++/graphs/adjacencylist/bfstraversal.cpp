#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;


template<typename T>
class graphs{
    unordered_map<T, list<T>> mp;
    public:

        void insertnode(T n, T e){
            mp[n].push_back(e);
            mp[e].push_back(n);
        }

        void bfssearch(T source){
            unordered_map<T, bool> visited;
            visited[source] = true;

            queue<T> q;
            q.push(source);

            T front;
            typename list<T>::iterator it;          // when you're declaring one more variable depending on previous template

            while(!q.empty()){
                front = q.front();
                q.pop();
                cout << front << " " ;
                for(it = mp[front].begin(); it!=mp[front].end(); it++){
                    // cout << "visited[*it]: " << *it << " " << visited[*it] << endl;
                    if(!visited[*it]){
                        q.push(*it);
                        visited[*it] = true;
                    }

                }
            }
        }

};

int main(){
    int n, e;
    cin >> n >> e;
    graphs<int> g;

    int s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d;
        g.insertnode(s,d);
    }  

    g.bfssearch(0);
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