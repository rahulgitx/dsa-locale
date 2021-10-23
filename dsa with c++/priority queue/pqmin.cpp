// time complexity for this heap  = O(nlogn)
// space complexity for this heap = O(n)

#include <bits/stdc++.h>
using namespace std;

class pqmin{
    vector<int> v;      
    public:
        pqmin(){
          }
        int isempty(){
            return v.size() == 0;
        }
        int getsize(){
            return v.size();
        }
        int getMin(){
            return v[0];
        }
        void insert(int a){
            v.push_back(a);
            int childindex = v.size()-1 ;
            while(childindex > 0){
                int parentindex = (childindex - 1)/2;

                if(v[parentindex] > v[childindex]){
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
        int removemin(){
            int ans = v[0];
            v[0] = v[v.size()-1];
            v.pop_back();
            int parent = 0;
            int child1 = 1;
            int child2 = 2;
            
            while(child1 <= v.size()-1){
                int min = parent;
                if(v[min] > v[child1]){
                    min = child1;
                }
                if(v[min] > v[child2] && child2 <= v.size()-1){
                    min = child2;
                }
                if(min == parent){
                    break;
                }
                int temp = v[parent];
                v[parent] = v[min];
                v[min] = temp;

                parent = min;
                child1 = parent*2+1;
                child2 = parent*2+2;
            }
            return ans;
        }
};

int main(){
    pqmin p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << "getsize(): " << p.getsize() << endl;
 
    cout << "getmin(): " << p.getMin() << endl;
    cout << "isempty(): " << p.isempty() << endl;
    while(!p.isempty()){
        cout << p.getMin() << " ";
        p.removemin();
    }

}