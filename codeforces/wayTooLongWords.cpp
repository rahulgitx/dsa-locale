#include <bits/stdc++.h>
using namespace std;

int getNoOfDigits(int n){
    int res = 0;
    while(n>0){
        n = n/10;
        res++;
    }
    return res;
}
string intToString(int n){
    string res = "";
    // int noOfDigs = getNoOfDigits(n);
    while(n>0){
        res += n%10+'0';
        n = n/10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        if(s.size()<=10) {
            cout << s << endl;
            continue;
        }

        string res = "";
        res += s[0];
        res += intToString(s.size()-2);
        res += s.back();
        cout << res << endl;
    }
}