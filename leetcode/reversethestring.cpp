#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "Hello my name is Suzi.";
    for (int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            cout << "space" << endl;
        }
    }
}