#include <iostream>
#include <unordered_map>
using namespace std;

class node{
    public:
        char c;
        unordered_map<char, node*> mp;
        int isTerminal;
        node(char c){
            this->c = c;
            this->isTerminal = false;
        }
};

class trie{
    node* root = new node('\0');
    public:
        void insert(const string &s){
            node* temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    node* newnode = new node(s[i]);
                    temp->mp[s[i]] = newnode;
                    temp = newnode;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            temp->isTerminal = true;
        }

        int search(const string &s){
            node* temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    // cout << "Word not present";
                    return 0;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            return temp->isTerminal;
        }

        int remove(const string &s){
            node* temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    return 0;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            if(temp->isTerminal){
                temp->isTerminal--;
                return 1;
            }
        }
};

int main(){
    trie dict;
    dict.insert("abc");
    dict.insert("abd");
    dict.insert("bca");
    dict.insert("abce");
    cout << dict.search("a");
}

