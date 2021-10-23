#include <bits/stdc++.h>
using namespace std;

void findl(vector<int> arr, vector<int> &larr, int n){
    stack<int> s;
    for (int i=0; i<n; i++){
        if(s.empty()){
            larr.push_back(0);
        }
        else{
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                larr.push_back(s.top()+1);
            }
            else{
                larr.push_back(0);
            }
        }
        s.push(i);
    }
}

void findr(vector<int> arr, vector<int> &rarr, int n){
    stack<int> s;
    for (int i=n-1; i>=0; i--){
        if(s.empty()){
            rarr.push_back(n-1);
        }
        else{
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                rarr.push_back(s.top()-1);
            }
            else{
                rarr.push_back(n-1);
            }
        }
        s.push(i);
    }
    reverse(rarr.begin(), rarr.end());
}

int maxfloor(vector<int> arr, int n){
    vector<int> larr;
    vector<int> rarr;
    findl(arr, larr, n);
    findr(arr, rarr, n);


    // for (int i=0; i<n; i++){
    //     cout << larr[i] << " ";
    // }
    // cout << endl;
    // for (int i=0; i<n; i++){
    //     cout << rarr[i] << " ";
    // }
    // cout << endl;
    
    int max = 0;
    for (int i=0; i<n; i++){
        // cout << (rarr[i]-larr[i]+1)*arr[i] << " ";
        if (max <  (rarr[i]-larr[i]+1)*arr[i] ){
            max = (rarr[i]-larr[i]+1)*arr[i];
        }
    }
    // cout << "max: " << max << endl;
    return max;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int output = maxfloor(arr, n);
    cout << output;
}