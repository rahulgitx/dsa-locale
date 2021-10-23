#include <iostream>
using namespace std;

int main(){
    // string s = "abcdefghij";
    // if (s[0] == 'a'){
    //     cout << "found";
    // }



}

// solution
/*
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> m;
        m['M']=1000;
        m['D']=500;
        m['C']=100;
        m['L']=50;
        m['X']=10;
        m['V']=5;
        m['I']=1;
        for (int i = 0; i<s.length(); i++){
            if (m[s[i]] >= m[s[i+1]]){
                sum += m[s[i]];
            }
            else{
                sum += (m[s[i+1]]-m[s[i]]);
                i++;
            }
        }
        return sum;
    }
    
};*/