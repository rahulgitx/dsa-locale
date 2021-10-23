// time complexity : (nlogk)

#include <iostream>
#include <queue>
using namespace std;

void ksmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(){
    int n = 7;
    int arr[] = {5,6,9,12,3,13,2};
    int k = 3;

    ksmallest(arr, n, k);
}