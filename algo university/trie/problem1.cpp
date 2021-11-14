#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct node{
    char c;
    unordered_map<char, node*> mp;
    int isterminal;
    node(char c){
        this->c = c;
        this->isterminal = 0;
    }

};

class trie{
    public:
        node *root = new node('\0');
        void insertstring(string s){
            node *temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    node *newnode = new node(s[i]);
                    temp->mp[s[i]] = newnode;
                    temp = temp->mp[s[i]]; 
                }
                else{
                    temp = temp ->mp[s[i]];
                }
            }
            temp->isterminal++;
        }

        void searchstring(string s){
            node *temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    cout << 0 << endl;
                    return;
                }
                else{
                    temp=temp->mp[s[i]];
                }
            }
            if(temp->isterminal == 0){
                cout << 0 << endl;
                return;
            }
            else{
                cout << 1 << endl;
                return;
            }
        }
        void searchprefix(string s){
            node *temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    cout << 0 << endl; 
                    return;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            cout << 1 << endl;
            return;
        }
};

int main(){
    int n;
    cin >> n;
    string s;
    int opt;
    vector<int> options;
    vector<string> str;
    for(int i=0; i<n; i++){
        cin >> opt;
        cin >> ws;
        options.push_back(opt);
        getline(cin, s);
        str.push_back(s);
    }

    trie t;
    for(int i=0; i<options.size(); i++){
        if(options[i] == 1){
            t.insertstring(str[i]);
        }
        else if(options[i] == 2){
            t.searchstring(str[i]);
        }
        else{
            t.searchprefix(str[i]);
        }
    }
}

/*
5
1 termite
2 term
3 term
1 term
2 term
*/