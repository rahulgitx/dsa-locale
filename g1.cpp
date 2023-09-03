#include <bits/stdc++.h>
using namespace std;


string func(string &s){
    bool cap = false;
    bool small = false;
    bool dig = false;
    bool chr = false;
    for(int i=0; i<s.length(); i++){
        if('A' <= s[i] && 'Z' >= s[i]){
            cap = true;
        }
        if('a' <= s[i] && 'z' >= s[i]){
            small = true;
        }
        if(0 <= s[i]-'0' && 9 >= s[i]-'0'){
            dig = true;
        }
        if(s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&'){
            chr = true;
        }
    }
    cout << "cap " << cap << " small: " << small << " dig: " << dig << " chr: " << chr << endl;

    while(!cap || !small || !dig || !chr){
        if(!cap){
            s += 'A';
            cap = true;
        }
        if(!small){
            s += 'a';
            small = true;
        }
        if(!dig){
            s += '1';
            dig = true;
        }
        if(!chr){
            s += '@';
            chr = true;
        }
    }
    if(s.length() < 7){
        int a = 7-s.length();
        for(int i=0; i<a; i++){
            s += '1';
        }
    }   
    return s;
}
int main(){
    int t;
    cin >> t;
    cin >> ws;
    for(int i=0; i<t; i++){
        int temp;
        cin >> temp;
        string s;
        cin >> s;
        cout << func(s) << endl;
        // cout << s << endl;
    }
}