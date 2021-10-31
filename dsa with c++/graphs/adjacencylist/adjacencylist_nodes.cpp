#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    unordered_map<string, list< pair<string, int> > > mp;
    public:
        void addedges(string n, string e, int w, bool directed){
            mp[n].push_back(make_pair(e, w));
            if(directed){
                mp[e].push_back(make_pair(n, w));
            }
        }
        void printedges(){
            unordered_map<string, list< pair<string, int> > >::iterator it;
            for(it = mp.begin(); it!=mp.end(); it++){
                cout << "vertex: " << it->first << " -> ";
                list< pair<string, int> >::iterator i;
                for(i = it->second.begin(); i!=it->second.end(); i++){
                    cout << "(" << i->first << "," << i->second << ") ";
                }
                cout << endl;
            }
        }
};

int main(){
    graph g;
    g.addedges("A","B",20,true);
    g.addedges("A","C",10,true);
    g.addedges("A","D",50,true);
    g.addedges("A","B",20,true);
    g.addedges("A","B",20,true);
    g.printedges();
}