#include <bits/stdc++.h>
using namespace std;

void findlmax(vector<int> arr, vector<int> &leftmax, int n){
    stack<int> s;
    for (int i=0; i<n; i++){
        if(s.empty()){
            s.push(0);
            leftmax.push_back(0);
        }
        else{
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(!s.empty()){
                leftmax.push_back(s.top()+1);
            }
            else{
                leftmax.push_back(0);
            }
        }
        s.push(i);
    }
}

void findrmax(vector<int> arr, vector<int> &rightmax, int n){
    stack<int> s;
    for (int i=n-1; i>=0; i--){
        if(s.empty()){
            s.push(n-1);
            rightmax.push_back(n-1);
        }
        else{
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(!s.empty()){
                rightmax.push_back(s.top()-1);
            }
            else{
                rightmax.push_back(n-1);
            }
        }
        s.push(i);
    }
    reverse(rightmax.begin(), rightmax.end());
}

int maxarea(vector<int> arr, int n){
    vector<int> leftmax;
    vector<int> rightmax;
    findlmax(arr, leftmax, n);
    findrmax(arr, rightmax, n);
    
    for (int i=0; i<n; i++){
        cout << leftmax[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++){
        cout << rightmax[i] << " ";
    }
    cout << endl;

    int max = 0;
    for (int i=0; i<n; i++){
        if(max < (rightmax[i]-leftmax[i]+1) * arr[i] ){
            max = (rightmax[i]-leftmax[i]+1) * arr[i]  ;
        }
    }
    return max;
}

int main(){
    int n = 6;
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(1);

    int output = maxarea(arr, n);
    cout << output;
}


/*
There are N buildings in a row. The i-th building has f_i floors. Each building is connected to the previous and next building.
That is, building i is connected to buildings i, i+1. You want to rent many floors in many buildings. 
For simplicity, you decided that you will only rent floors from connected buildings.
So, if you rent from building i and j you must also rent floors from any building in between them.
You also decided that if you rent the k-th floor of some building, then in every building that you rent, 
there must exist the k-th floor and you must rent it.
*/