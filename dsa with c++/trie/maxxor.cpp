#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node{
    int bin;
    unordered_map<int, node*> mp;
    int isterminal;
    node(int b){
        this->bin = b;
        this->isterminal = 0;
    }
};

class trie{
    node *root = new node(-1);
    public:
        void insertnum(int n){
            node* temp = root;
            int k;
            for(int i=31; i>=0; i--){
                k = (n >> i);
                k = (k&1);
                if(temp->mp.count(k) == 0){
                    node *newnode = new node(k);
                    temp->mp[k] = newnode;
                    temp = temp->mp[k];
                    // cout << k << " inserted"<< endl;
                }
                else{
                    temp = temp->mp[k];
                }
            }
            temp->isterminal = n;
            // cout << n << " digit has been inserted" << endl;
        }

        vector<int> maxfromtrie(int n){
            vector<int> ans;
            node *temp = root;
            int xorval = 0;
            for(int i=31; i>=0; i--){
                int cb = (n&(1<<i)) ? 1:0 ;        // current bit starting from the 32nd bit.
                if (temp->mp.count(cb^1) != 0){
                    // cout << "found different" << endl;
                    temp = temp->mp[cb^1];
                    xorval |= (1<<i);
                }  
                else{
                    // cout << "found same" << endl;
                    temp = temp->mp[cb];
                }
            }
            ans.push_back(xorval);
            ans.push_back(temp->isterminal);
            return ans;
        }


};

void maxxor(vector<int> arr){
    trie t;
    int maxxor = 0;
    int val1, val2;
    t.insertnum(arr[0]);
    vector<int> maxxorandval;
    for(int i=1; i<arr.size(); i++){
        // cout << "for i: " << i << endl;
        maxxorandval = t.maxfromtrie(arr[i]);
        if(maxxor < maxxorandval[0]){
            maxxor = maxxorandval[0];
            val1 = maxxorandval[1];
            val2 = arr[i];
            // cout << "values incremented" << endl;
        }
        t.insertnum(arr[i]);
        // cout << endl << endl;
    }

    cout << val1 << " " << val2;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    maxxor(arr);
}


/*
5
3 5 4 7 1
*/