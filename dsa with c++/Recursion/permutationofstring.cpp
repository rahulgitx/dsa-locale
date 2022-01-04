#include <bits/stdc++.h>
using namespace std;

// void swap(char &a, char &b){
//     char temp = a;
//     a = b; 
//     b = temp;
// }

void helper(vector<string> &ans, string &s, int index){
    if(index == s.length()-1){
        ans.push_back(s);
    }
    else{
        for(int i=index; i<s.length(); i++){
            swap(s[i], s[index]);
            helper(ans, s, index+1);
            swap(s[i], s[index]);
        }
    }
    // ans.push_back("aaksdfj;a");
}

vector<string> permutestring(string s){
    vector<string> ans;
    helper(ans, s, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    // s = "abcd";
    // swap(s[1], s[2]);
    // cout << s;
    getline(cin, s);
    // cout << s;
    vector<string> v = permutestring(s);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    
}