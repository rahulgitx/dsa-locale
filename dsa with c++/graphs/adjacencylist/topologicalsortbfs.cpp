#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class graphs{
    int n;
    list<int>* l;
    public:
        graphs(int n){
            this->n = n;
            l = new list<int>[n];
        }

        void insertedges(int n, int e){
            l[n].push_back(e);
        }

        void topologicalsort(){
            int* indegree = new int[n];

            for(int i=0; i<n; i++){
                indegree[i] = 0;
            }
            for(int i=0; i<n; i++){
                for(auto j : l[i]){
                    indegree[(j)]++;
                }
            }

            queue<int> ansq;
            for(int i=0; i<n; i++){
                if(indegree[i] == 0){
                    ansq.push(i);
                }
            }

            int front;
            cout << "output; " << endl;
            while(!ansq.empty()){
                front = ansq.front();
                ansq.pop();
                cout << front << " ";

                for(auto i:l[front]){
                    indegree[i]--;
                    if(indegree[i] == 0){
                        ansq.push(i);
                    }
                }

            }
        }
};

int main(){
    int n, e;
    cin >> n >> e;
    graphs g(6);

    int s, d;
    for(int i=0; i<e; i++){
        cin >> s >> d;
        g.insertedges(s, d);
    }

    g.topologicalsort();
}

/*
6 7
0 2
1 2
1 4
2 3
2 5
4 5
3 5
*/