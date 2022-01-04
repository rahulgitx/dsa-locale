#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int j, int i){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

vector<vector<int>> ans;

void permute(vector<int> &v, int index){
    if(index == v.size()-1){
        ans.push_back(v);
        // cout << "ans" << ans[0][0];
    }
    else{   
        for(int i=index; i<v.size(); i++){
            swap(v, index, i);
            permute(v,  index+1);
            swap(v, index, i);
        }
    }
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    permute(arr, 0);
    // cout << "back";
    for( auto i:ans){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

/*
3
1 2 3
*/