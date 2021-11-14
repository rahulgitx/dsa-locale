// test cases to be taken care of : 
// 1. the input strings can be palindrome themselves
// 2. The count of ordered pairs can be different if current string is itself palindrome or not

#include <bits/stdc++.h>
using namespace std;

struct node{
    char c;
    unordered_map<char, node*> mp;
    int isterminal;
    node(char c){
        this->c = c;
        isterminal = 0;
    }
};

class trie{
    public:
        node* root = new node('\0');
        void insertstring(string s){
            node *temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    node *newnode = new node(s[i]);
                    temp->mp[s[i]] = newnode;
                    temp = temp->mp[s[i]];
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            temp->isterminal++;
        }

        int nopalinds(string s){
            node *temp = root;
            for(int i=s.length()-1; i>=0; i--){
                if(temp->mp.count(s[i]) == 0){
                    return 0;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            return temp->isterminal;
        }


};

bool ispalindrome(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i] == s[s.length()-1-i]){

        }
        else{
            return false;
        }
    }
    return true;
}

int findfunc(vector<string> strvect){
    int ordered_pairs = 0;
    int nopalindromes = 0;
    trie t;
    for(int i=0; i<strvect.size(); i++){
        t.insertstring(strvect[i]);
        nopalindromes = t.nopalinds(strvect[i]);
        if(ispalindrome(strvect[i])){
            ordered_pairs += 1 + 2*(nopalindromes-1);
        }
        else{
            ordered_pairs += 2*nopalindromes;
        }

    }
    return ordered_pairs;
}

int main(){
    int n;
    cin >> n;
    vector<string> s;
    string temp;
    cin >> ws;
    for(int i=0; i<n; i++){
        getline(cin, temp);
        s.push_back(temp);
    }
    // for(int i=0; i<s.size(); i++){
    //     cout << s[i] << " ";
    // }
    cout << findfunc(s);
}


/*
3
aba
cde
edc
*/

/*
6
rat
tar
art
rta
tra
ata
*/