#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int smallestLeftOut(string& s, unordered_map<string, int>& mp, int startIndex, int lastIndex){
    string temp = "";
    for(int k=startIndex; k<=lastIndex; k++){
        temp += s[k];
    }

    cout << "temp: " << temp << endl;

    while(temp.size()){
        if(mp[temp]) return (lastIndex-startIndex+1)-temp.size();
        temp = temp.erase(0,1);
    }
    return (lastIndex-startIndex+1);
}

int main(){
    vector<vector<int>> v;
    vector<int> temp1;
    temp1.push_back(1);
    vector<int> temp2;
    temp2.push_back(2); temp2.push_back(3);
    v.push_back(temp1);
    v.push_back(temp2);
    v[0].push_back(5);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

