#include <iostream>
#include <queue>
using namespace std;

// priority_queue<int, vector<int>, greater<int>> pq                      for min queue
// by default uses max queue
int main(){
    priority_queue<int> pq;        
    pq.push(23);
    pq.push(34);
    pq.push(4);
    pq.push(22);
    pq.push(55);
    pq.push(45);
    pq.push(32);

    cout << "size: " << pq.size() << endl;
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}