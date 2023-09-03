#include <bits/stdc++.h>
using namespace std;

bool helper(string a, string b){
    static map<pair<string, string>, bool> mp;
    if(mp.count({a,b}) > 0){
        // cout << "thisone";
        return mp[{a,b}];
    }
    if(a == b){
        mp[{a,b}] = true;
        return mp[{a,b}];
    }
    if(a.length() != b.length()){
        mp[{a,b}] = false;
        return mp[{a,b}];
    }
    if(a.length() == 1){
        if(a != b){
            mp[{a,b}] = false;
            return mp[{a,b}];
        }
    }

    int i=0, j = a.length()-1;
    bool flag = false;
    string a1, a2, b1, b2, b3, b4;
    for(int k=i; k<j; k++){
        a1 = a.substr(i,k+1);
        a2 = a.substr(k+1,j-k);
        b1 = b.substr(i,k+1);
        b2 = b.substr(k+1,j-k);
        b3 = b.substr(j-k, k+1);
        b4 = b.substr(i,j-k);
        cout << "a1: "<< a1;
        cout << " a2: "<< a2;
        cout << " b1: "<< b1;
        cout << " b2: "<< b2;
        cout << " b3: "<< b3;
        cout << " b4: "<< b4 << endl;
        if(
            (helper(a1,b1) && helper(a2, b2))// non-swap
            || (helper(a1, b3) && helper(a2, b4))  // swap
        ){
            flag = true;
            break;
        }
        else{
            continue;
        }
    }

    mp[{a,b}] = flag;
    return mp[{a,b}];
}

// bool scrambledmemo(string a, string b){
    
//     return helper(a, b, mp);
// }

bool scrambled(string a,  string b){
    if(a == b){
        return true;
    }
    if(a.length() != b.length()){
        return false;
    }
    if(a.length() == 1){
        if(a != b){
            return false;
        }
    }

    int i=0, j = a.length()-1;
    bool flag = false;
    string a1, a2, b1, b2, b3, b4;
    for(int k=i; k<j; k++){
        a1 = a.substr(i,k+1);
        a2 = a.substr(k+1,j-k);
        b1 = b.substr(i,k+1);
        b2 = b.substr(k+1,j-k);
        b3 = b.substr(j-k, k+1);
        b4 = b.substr(i,j-k);
        if(
            (scrambled(a1,b1) && scrambled(a2, b2))// non-swap
            || (scrambled(a1, b3) && scrambled(a2, b4))  // swap
        ){
            flag = true;
            break;
        }
        else{
            continue;
        }
    }
    return flag;

}

int main(){
    string a, b;
    cin >> a >> b;
    // cout << a.substr(0,1);
    cout << helper(a, b);
}

/*
great
rgeat
*/

/*
abcde
caedbd
*/

/*
a
a
*/

/*
ba
ab
*/

/*
abb
bba
*/