// heapifying using O(n) time complexity

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void heapify(vector<int> &v){
    cout << "heapify called: " << endl;
    for (int i=((v.size()/2)-1); i>=0; i--){
        
        int parent = i;
        int min = parent;
        int child1 = parent*2+1;
        int child2 = parent*2+2;
  
        
        while( child1 < v.size() ){
            min = parent;
            
            if(v[min]>v[child1]){
                min = child1;
            }
            if(v[min]>v[child2] && child2 < v.size()){
                min = child2;
            }
            if(parent == min){
                break;
            }
            int temp = v[min];
            v[min] = v[parent];
            v[parent] = temp;
            
            parent = min;
            child1 = parent*2+1;
            child2 = parent*2+2;
        }
    }
}

int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(5);
    v.push_back(10);
    v.push_back(30);

    heapify(v);

    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}