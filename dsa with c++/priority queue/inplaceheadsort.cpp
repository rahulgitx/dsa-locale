#include <bits/stdc++.h>
using namespace std;

void inplaceheap(vector<int> &arr){
    //heapify
    for(int i=1; i<arr.size(); i++){
        int child = i;
        while(child > 0){
            int parent = (child-1)/2;
            if(arr[parent] > arr[child]){
                int temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
            }
            else{
                break;
            }
            child = parent;
        }
    }

    // down heapify or remove out
    for (int i=arr.size()-1; i>0; i--){

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int parent = 0;
        int child1 = 1, child2 = 2;

        while(child1 < i){
            int min = parent;
            
            if(arr[min] > arr[child1]){
                min = child1;
            }
            if(arr[min] > arr[child2] && child2 < i){
                min = child2;
            }

            if(min == parent){
                break;
            }
            
            temp = arr[min];
            arr[min] = arr[parent];
            arr[parent] = temp;

            parent = min;
            child1 = parent*2+1;
            child2 = parent*2+2;
        }
                
    }
}


int main(){
    vector<int> v;
    v.push_back(100);
    v.push_back(45);
    v.push_back(34);
    v.push_back(78);
    v.push_back(50);
    v.push_back(11);

    inplaceheap(v);

    for(int i=0; i<v.size()-1; i++){
        cout << v.at(i) << " ";
    }
}