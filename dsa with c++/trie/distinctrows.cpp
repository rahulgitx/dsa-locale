#include <iostream>
#include <unordered_map>
using namespace std;

struct node{
    int no;
    unordered_map<int, node*> mp;
    int isterminal;
    node(int n){
        this->no = n;
        this->isterminal = 0;
    }
};

class trie{
    public:
        node *root = new node(-1);
        void insertnode(int arr[], int n){
            node *temp = root;
            for(int i=0; i<n; i++){
                if(temp->mp.count(arr[i]) == 0){
                    node *newnode = new node(arr[i]);
                    temp->mp[arr[i]] = newnode;
                    temp = temp->mp[arr[i]];
                }
                else{
                    temp = temp->mp[arr[i]];
                }
                // cout << arr[i] << " ";
            }
            // cout << endl;
            temp->isterminal++;
        }
        void dfsrun(node* root, int &nodist){
            for(auto i:root->mp){
                dfsrun(i.second, nodist);
            }
            if(root->isterminal > 0){
                nodist++;
            }
        }
};

void nodistinct(int arr[][5], int n, int m){
    trie t;
    for(int i=0; i<n; i++){
        t.insertnode(arr[i], m);
    }

    int nodist = 0;
    t.dfsrun(t.root, nodist);
    cout << nodist;
}

int main(){
    int arr[4][5] = {
        {0,1,1,0,1},
        {0,1,0,0,1},
        {1,0,0,1,0},
        {0,1,1,0,1}
    };

    nodistinct(arr, 4, 5);
    
}