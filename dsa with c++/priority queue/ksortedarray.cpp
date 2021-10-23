#include <iostream>
#include <queue>
using namespace std;

void ksortedarray(int arr[], int n, int k){
    priority_queue<int> pq;
    for (int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    int j=0;
    for(int i=k; i<n; i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}


int main(){
    int arr[] = {5,7,4,6,3,2};
    int k=3, n=5;   

    ksortedarray(arr, n, k);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}