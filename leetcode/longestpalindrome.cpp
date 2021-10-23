#include <iostream>
using namespace std;


bool ispalindrome(string ss){
    string reverse = "";
    for (int i=ss.length()-1; i>=0; i--){
        reverse += ss[i];
    }
    if(reverse == ss){
        return true;
    }
    else{
        return false;
    }
}
string longestPalindrome(string s) {
        string reverse="";
        for(int i=s.length()-1; i>=0; i--){
            reverse += s[i];
            cout << "appending to the reverse" << endl;
        }
        cout << "reverse: " << reverse << endl;
        string longest = "", temp="";

        string longest = "";
        for (int i=0; i<s.length(); i++){
            for (int j=0; j<i; j++){
                string temp = "";
                if(s[j] == reverse[s.length()-1-i+j]){
                    temp += s[j];
                }
            }
        }

        // int i=0, j=0, matched = 0; 
        // while(i<s.length()){
        //     if(matched=0){
        //         j = s.length()-i;
        //     }
        //     cout << "s[i]: " << s[i] << " reverse[j]: " << reverse[j] << " ";
        //     if(s[i]==reverse[j]){
        //         cout << "char matched! " ;
        //         temp += s[i];
        //         i++; j++; matched = 1;
        //     }
        //     else if (s[i] != reverse[j] && matched == 1){
        //         j = s.length()-i; temp = ""; matched = 0;
        //         cout << " last time matched but not this time ";
        //         // if(i==s.length()-1){
        //         //     break;
        //         // }
        //     }
        //     else{
        //         cout << "not matched ";
        //         j++;
        //     }
        //     cout << "temp: " << temp << " ";
        //     if(temp.length() > longest.length()){
        //         longest = temp;
        //     }
        //     if(j==s.length()){
        //         j=0;  matched = 0; temp = "";
        //     }
        //     cout << endl;
        // }
        return longest;
}

int main(){
    string s = "aacabdkacaa";//"babad";//"cdbabade";
    // cout << s.substr(3,6);
    string temp = s.substr(0,2);
    // cout << ispalindrome(temp);
    // cout << s.substr(0,3);

    cout << longestPalindrome(s);
}



/*int i=0, j=s.length()-1;
    string temp;
    while( i<=j){
        if(s[i] == s[j]){
            if(ispalindrome(s.substr(i,j))){
                temp = (s.substr(i,j));
                break;
            }
            else{
                i++; j--;
            }
        }
        else if((j-i) == 1){
            temp = (s.substr(i,j));
            break;
        }
        else{
            i++; j--;
        }
    }
    return temp;*/