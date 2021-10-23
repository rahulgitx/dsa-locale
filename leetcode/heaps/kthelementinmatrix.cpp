#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    int n = 0;
    int i,j;
    for (i=0; i<matrix.size(); i++){

        for (j=0; j<matrix[i].size(); j++){
            pq.push(matrix[i][j]);
            n++;
            if(n == k){
                break;
            }
        }
        if(n == k){
            break;
        }
    }
    if(j == matrix.size()-1){
        j = 0;
        if(i == matrix.size()-1){
            cout << "returning earlier" << endl;
            return pq.top();
        }
    }
    else{
        i++; j++;
    }
    
    cout << i << " " << j << " "  << endl;
    cout << "pq.top: " << pq.top() << endl;
    int top;
    for (  ; i<matrix.size(); i++){
        for (  ; j<matrix[i].size(); j++){
            top = pq.top();
            if(matrix[i][j] < top){
                pq.pop();
                pq.push(matrix[i][j]);
            }
        }
    }
    return pq.top();
}

int main(){
    vector<vector<int>> v
    {
        {1,2},
        {3,3}
    };
    // cout << v[1][1];
    int k=2;
    int output = kthSmallest(v,k);
    cout << output;
}