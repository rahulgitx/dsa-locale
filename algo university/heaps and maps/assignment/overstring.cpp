#include <bits/stdc++.h>
using namespace std;

bool aremapsequal(unordered_map<char, int> tmap, unordered_map<char, int> substringmap){
    unordered_map<char,int>::iterator it;
    bool ans = true;
    for(it=tmap.begin(); it!=tmap.end(); it++){
        if(substringmap[it->first] == it->second){
            ans = true;
        }
        else{
            return false;
        }
        return ans;
    }
}

int overstring(string s, string t){

    unordered_map<char, int> tmap;        //making the map for characters of t
    for(int i=0; i<t.length(); i++){
        tmap[t[i]]++;
    }

    unordered_map<char, int> substrmap;
    int i=0, j=0;
    while(j<s.length()-1){ 

        if( !(tmap.count(s[i])>0)){   // if first char is not matched move i  and j too if its at same position
            i++;
            if(j<=i){
                j++;
            }
        }

        if( tmap.count(s[j])>0 ){
            substrmap[s[j]]++;
            j++;
        }

    }

}

int main(){
    string s = "dacbdaeecbcdacb";
    string t = "becccba";
}