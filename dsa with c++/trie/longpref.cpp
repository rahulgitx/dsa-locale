#include <iostream>
#include <string>
#include <vector>
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

        void insertword(string s){
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

        int dfsrun(node* root, int depth, int &long_pref){
            int nmberstringsendingfromhere = 0;
            if(root->isterminal > 0){
                nmberstringsendingfromhere += root->isterminal;
            }
            for(auto i : root->mp){
                nmberstringsendingfromhere += dfsrun(i.second, depth+1, long_pref);
            }
            if(nmberstringsendingfromhere > 1){
                long_pref = max(depth, long_pref);
            }
            cout << "longpref till now: " << long_pref << endl;
            
            return nmberstringsendingfromhere;
        }
};

void longpref(vector<string> arr){
    trie t;
    for(int i=0; i<arr.size(); i++){
        t.insertword(arr[i]);
    }

    int long_pref = 0;

    t.dfsrun(t.root, 0, long_pref);

    cout << "longpref" << long_pref;

}


int main(){
    int n;
    cin >> n;
    cin >> ws;                      // gets rid of the unwanted whitespace created after inputing the value of n
    string temp;
    char a;
    vector<string> input;
    for(int i=0; i<n; i++){
        getline(cin, temp);
        // cin >> a;
        // cout << temp;
        input.push_back(temp);
    }

    longpref(input);
}

/*
4
abcd
abdf
abdx
efab
*/

/*
6
abcdefg
abcedgg
abcabab
beacbb
dddabcdef
dddabcdef
*/

/*
6
abcdefg
abcedgg
abcabab
beacbb
dddabcdef
dddabcde
*/