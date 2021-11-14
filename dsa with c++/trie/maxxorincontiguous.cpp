#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node{
    unsigned int bin;
    unordered_map<unsigned int, node*> mp;
    unsigned int isterminal;
    node(unsigned int b){
        this->bin = b;
        this->isterminal = -1;
    }
};


class trie{
    node *root = new node(-1);
    public:
        void insertcont(int x){
            node* temp = root;
            for(int i=31; i>=0; i--){
                unsigned cb = x&(1 << i) ? 1 : 0;
                if(temp->mp.count(cb) == 0){
                    node *newnode = new node(cb);
                    temp->mp[cb] = newnode;
                    temp = temp->mp[cb];
                }
                else{
                    temp = temp->mp[cb];
                }
            }
            temp->isterminal = x;
            cout << x << " inserted"<< endl;
        }
        vector<unsigned int> findmax(unsigned int x){
            cout << "finding max for : " << x << endl;
            vector<unsigned> ans;
            node* temp = root;
            unsigned maxxor = 0;
            for(int i=31; i>=0; i--){
                unsigned cb = x&(1<<i) ? 1 : 0;
                if(temp->mp.count(cb^1) != 0){
                    temp = temp->mp[cb^1];
                    maxxor |= (1<<i);
                }
                else{
                    temp = temp->mp[cb];
                }
            }
            ans.push_back(temp->isterminal);
            ans.push_back(maxxor);
            return ans;
        }
};

void findmaxcontarr(vector<unsigned int> arr){
    trie t;
    vector<unsigned int> contig;
    contig.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++){
        contig.push_back((arr[i-1])^(arr[i]));
    }
    for(int i=0; i<contig.size(); i++){
        cout << contig[i] << " ";
    }
    cout << endl;

    unsigned maxxor = 0;
    int leftcont;
    int rightcont;
    t.insertcont(contig[0]);
    for(int i=1; i<contig.size(); i++){
        vector<unsigned> temp = t.findmax(contig[i]);
        if(maxxor < max(temp[1], contig[i])){
            maxxor = max(temp[1], contig[i]);
            leftcont = temp[0];
            rightcont = contig[i];
        }
        t.insertcont(contig[i]);
    }
    cout << "maxxor: " << maxxor << " leftcont: " << leftcont << " rightcont: " << rightcont;
}

int main(){
    unsigned int n;
    cin >> n;
    vector<unsigned int> input;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        input.push_back(temp);
    }

    findmaxcontarr(input);
}

/*
5
3 5 4 1 7
*/