#include <bits/stdc++.h>
using namespace std;
 

// Time complexity : O(n*l) where l  = length of string s
// Space complexity : O(l)
string solve(string s){
    string t = s;

    sort(t.begin(), t.end());
    if(s!=t){
        return t;
    }else{
        reverse(t.begin(), t.end());
        if(s!=t){
            return t;
        }else{
            return "IMPOSSIBLE";
        }
    }

}

int main()
{
    
   int n;
   cin>>n;
   for(int i = 0;i<n;i++){
       string s;
       cin>>s;

       
        cout<<"Case #" << (i+1) << ": " << solve(s)<<endl;
       
   }
    
    return 0;
}