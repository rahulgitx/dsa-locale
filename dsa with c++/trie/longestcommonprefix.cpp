// finding the longest substring in at least two of the strings from the given no of strings

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
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
    node* root = new node('\0');
    int longest = 0;
    public:
        void insert(const string s){
            node* temp = root;
            for(int i=0; i<s.length(); i++){
                if(temp->mp.count(s[i]) == 0){
                    node* newnode = new node(s[i]);;
                    temp->mp[s[i]] = newnode;
                    temp = newnode;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            temp->isterminal += 1;
        }
        // int count = 0;
        // node* temp = root;
        // int longest = 0;
        // stack<int> s;
        // s.push(count);
        void dfs(){
            
            node* temp = root;
            int count = 0;
            stack<int> s;
            s.push(0);
            // cout << s.top();
            longestprefix(temp, count, s);
            cout << "longest: " << longest;
        }
        void longestprefix(node* temp, int &count, stack<int> &s){
            // cout << temp->c << " "; 
            // unordered_map<char, node*>::iterator it;
            // for(it=temp->mp.begin(); it!=temp->mp.end(); it++){
            for(auto it : temp->mp){
                count++;
                // cout << "count: " << count << " ";
                if( it.second->mp.size() > 1){
                    s.push(count);
                    // cout << " diversion found" << " ";
                }
                longestprefix(it.second, count, s);
                // cout << "backfrom recursion: " << " ";
                // cout << s.top();
                count = s.top();
                // cout << count;
            }
            // cout << " for loop ended for: " << temp->c << " "; 
            if(s.top()>longest){
                longest = s.top();
            }
            if(temp->mp.size() > 2){
                s.pop();
            }
        }
      
};

int main(){
    vector<string> v;
    v.push_back("abcd");
    v.push_back("abdf");
    v.push_back("abdx");
    v.push_back("efab");

    trie t;
    for(int i=0; i<v.size(); i++){
        t.insert(v[i]);
    }
    t.dfs();
}