#include <iostream>
#include <list>
using namespace std;

class graph{
    list<int>* l;
    int n;
    public:
        graph(int n){
            this->n = n;
            l = new list<int>[n];
        }

        void addedges(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void printedges(){
            for(int i=0; i<n; i++){
                cout << "vertex: " << i << " -> ";
                list<int>::iterator it;
                for(it = l[i].begin(); it!=l[i].end(); it++){
                    cout << *(it) << ", ";
                }
                cout << endl;
            }
        }
        
};

int main(){
    graph g(4);  // graph having 4 nodes
    g.addedges(0,1);   // an edge from 0 -> 1 (ans also 1 -> 0 as per addedges' implementation)
    g.addedges(0,2);
    g.addedges(1,2);
    g.addedges(2,3);
    g.printedges();
}