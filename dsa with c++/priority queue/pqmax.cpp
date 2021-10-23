// time complexity for this heap  = O(logn)
// space complexity for this heap = O(n)


#include <bits/stdc++.h>
using namespace std;

class pqmax{
    vector<int> v;
    public:
        pqmax(){
          }
        int isempty(){
            return v.size() == 0;
        }
        int getsize(){
            return v.size();
        }
        int getmax(){
            return v[0];
        }
        void insert(int a){
            v.push_back(a);
            int childindex = v.size()-1 ;
            while(childindex > 0){
                int parentindex = (childindex - 1)/2;

                if(v[parentindex] < v[childindex]){
                    int temp = v[parentindex];
                    v[parentindex] = v[childindex];
                    v[childindex] = temp;
                }
                else{
                    break;
                }
                childindex = parentindex;
            }
        }
        int removemax(){
            int ans = v[0];
            v[0] = v[v.size()-1];
            v.pop_back();
            int parent = 0;
            int child1 = 1;
            int child2 = 2;
            
            while(child1 <= v.size()-1){
                int max = parent;
                if(v[max] < v[child1]){
                    max = child1;
                }
                if(v[max] < v[child2] && child2 <= v.size()-1){
                    max = child2;
                }
                if(max == parent){
                    break;
                }
                int temp = v[parent];
                v[parent] = v[max];
                v[max] = temp;

                parent = max;
                child1 = parent*2+1;
                child2 = parent*2+2;
            }
            return ans;
        }

};


int main(){
    pqmax p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << "getsize(): " << p.getsize() << endl;
 
    cout << "getmax(): " << p.getmax() << endl;
    cout << "isempty(): " << p.isempty() << endl;
    while(!p.isempty()){
        cout << p.getmax() << " ";
        p.removemax();
    }

}