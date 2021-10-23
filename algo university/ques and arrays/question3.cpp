#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void findl(vector<int> arr, vector<int> &range, int n){
    stack<int> s;
    int i=0;
    while(i<n){
        if(s.empty()){
            (range).push_back(0);
        }
        else{
            while( !s.empty() && arr[s.top()]>arr[i] ){ 
                    s.pop();
            }
            if(!s.empty()){
                (range).push_back(s.top()+1);
            }
            else{
                (range).push_back(0);
            }
        }
        s.push(i);
        i++;
    }
}

void findr(vector<int> arr, vector<int> &range, int n){
    stack<int> s;
    int i=n;
    while(i>-1){
        if(s.empty()){
            (range).push_back(n);
        }
        else{
            while( !s.empty() && (arr[s.top()] > arr[i]) ){
                s.pop();
            }
            if(!s.empty()){
                (range).push_back(s.top()-1);
            }
            else{
                (range).push_back(n-1);
            }
        }
        s.push(i);
        
        i--;
    }
    reverse(range.begin(), range.end());
}

void ans(vector<int> arr, int n){
    vector<int> lrange;
    vector<int> rrange;  
    findl(arr, lrange, n);
    findr(arr, rrange, n);

    for(int i=0; i<n; i++){
        cout  << lrange[i] << " ";
        // cout << (i-lrange[i]+1)*(rrange[i]-i+1) << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout <<  rrange[i] << " ";
        // cout << (i-lrange[i]+1)*(rrange[i]-i+1) << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++){
        cout << (i-lrange[i]+1)*(rrange[i]-i+1) << " ";
    }
    findr(arr, rrange, n);  
}

void test(vector<int> *arr, int n){
    for (int i=0; i<n; i++){
        (*arr).push_back(i);
    }
    for (int i=0; i<n; i++){
        cout << (*arr)[i];
    }
}

int main(){
    int n=7;
    vector<int> arr;
    arr.push_back(100);
    arr.push_back(80);
    arr.push_back(61);
    arr.push_back(70);
    arr.push_back(60);
    arr.push_back(75);
    arr.push_back(85);
    

    ans(arr, n);
}