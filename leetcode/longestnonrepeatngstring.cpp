#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// bruteforce
int longestbruteforce(string s){
    string longest = "";
    for (int i=0; i<s.length(); i++){
        unordered_map<char, int> mym;
        for (int j=i; j<s.length(); j++){
            if( !(mym.count(s[j])>0) ){
                mym[s[j]] = 1;
                // cout << "inserted" << " " ;
                if (j == (s.length()-1)){
                    string inp = "";
                    for (int k = i; k<=j; k++){
                        inp = inp + s[k];
                    }
                    if (inp.length() > longest.length()){
                        longest = inp;
                    }
                    break;
                }
            }
            else {
                string inp = "";
                for (int k = i; k<j; k++){
                    inp = inp + s[k];
                }
                if (inp.length() > longest.length()){
                    longest = inp;
                }
                break;
            }
            
        }
    }
    // cout << "longest: " << longest << endl;
    return longest.length();
}

// O(n)   accepted
int longest(string s){
    unordered_map<char, int> mymap;
    int i=0, j=0, len = 0, lastpoint = 0, longest = 0;
    while (j<s.length()){
        if(!(mymap.count(s[j])>0)){
            mymap[s[j]] = j;
            len++;
        }
        else{
            lastpoint = i;
            i = mymap[s[j]]+1;
            for(int k = lastpoint; k<i; k++){
                mymap.erase(s[k]);
            }
            mymap[s[j]] = j;
            len = j-i+1;
        }
        if(longest < len){
            longest = len;
        }
        cout << "longest: " << longest << " j: " << j << " i: " << i << endl;
        j++;
    }
    return longest;
}

int main(){
    string s = "poabcdefaklmabcdbb";
    // int output = longestbruteforce(s);

    int output = longest(s);
    cout << output << endl;


    // cout << s[1] << "space";

    // unordered_map<char, int> m;
    // m[' '] = 1;
    // cout << m.count(' ');
}
