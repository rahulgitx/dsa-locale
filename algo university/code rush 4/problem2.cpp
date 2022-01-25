#include <bits/stdc++.h>
using namespace std;

string ans(string s){
    if(s.size() == 1){
        return s;
    }
    else if (s.size() == 2){
        if(s[0] == s[1]){
            if(s[0] != 'a'){
                s[0] = 'a';
            }
            else{
                s[0] = 'b';
            }
        }
        else{
            return s;
        }
    }

    int i=1;
    while(i < s.size()){
        if(i == 1 && s[0] != s[1] ){
            i++;
            continue;
        }
        if(s[i-1] == s[i] || s[i+1] == s[i]){
            if(s[i-1] != 'a' && s[i+1] != 'a'){
                s[i] = 'a';
            }
            else if(s[i-1] != 'b' && s[i+1] != 'b'){
                s[i] = 'b';
            }
            else{
                s[i] = 'c';
            }
        }

        if(i+2 < s.size()){
            if(s[i+1]==s[i+2]){
                i += 2;
            }
            else{
                i += 3;
            }
            if(i == s.size()-1){
                if(s[i-1]==s[i]){
                    if(s[i] != 'a'){
                        s[i] = 'a';
                    }
                    else{
                        s[i] = 'b';
                    }
                }
            }
        }
        else{
            break;
        }
    }

    return s;
}

int main(){
    string s;
    cin >> s;
    cout << ans(s);
}

/*
aab
*/

/*
abcxxxyzz
*/

/*
abbba
*/

/*
abbbaaafghhgkll
*/

/*
zzzzzzz
*/

/*
bbbaabbbaa
*/

/*
zzzz
*/