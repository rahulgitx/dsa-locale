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
    unordered_map<string, int> mp;
    mp["leet"]++;
    mp["code"]++;
    mp["leetcode"]++;
    string s = "code";

    cout << "Smallest leftout : " << smallestLeftOut(s, mp, 0, s.size()-1);
}

