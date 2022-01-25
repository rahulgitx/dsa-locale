#include <bits/stdc++.h>
using namespace std;

string addbinary(string a, string b){
    string big, small;
    if(a.length() > b.length()){
        big = a;
        small = b;
    }
    else if(b.length() >= a.length()){
        big = b;
        small = a;
    }
    int diff = big.length()-small.length();
    string x = "";
    for(int i=0; i<diff; i++){
        x += "0";
    }
    small = x+small;
    cout << "small: " << small << " big: " << big << endl;
    // return small;


    vector<char> ans;
    int carry = 0;
    for(int i=big.length()-1; i>=0; i--){
        if(big[i] == '1' && small[i] == '1' && carry == 0){
            ans.push_back('0');
            carry = 1;
        }
        else if(big[i] == '1' && small[i] == '1' && carry == 1){
            ans.push_back('1');
            carry = 1;
        }
        else if((big[i] == '0' && small[i] == '1' && carry == 0) || (big[i] == '1' && small[i] == '0' && carry == 0) ){
            ans.push_back('1');
            carry = 0;
        }
        else if(big[i] == '0' && small[i] == '0' && carry == 0){
            ans.push_back('0');
            carry = 0;
        }
        else if((big[i] == '0' && small[i] == '1' && carry == 1) || (big[i] == '1' && small[i] == '0' && carry == 1)){
            ans.push_back('0');
            carry = 1;
        } 
        else if(big[i] == '0' && small[i] == '0' && carry == 1){
            ans.push_back('1');
            carry = 0;
        }
        cout << "big[" << i << "]: " << big[i] << " small[" << i << "]: " << small[i] << " carry: " << carry << endl;
    }
    if(carry == 1){
        ans.push_back('1');
    }

    string answer;
    for(int i=ans.size()-1; i>=0; i--){
        answer += ans[i];
    }
    return answer;
}

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << addbinary(a, b);
}


/*
11
1
ans=100
*/

/*
1010
1011
ans=10101
*/