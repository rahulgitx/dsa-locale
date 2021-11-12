#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct node{
    int bin;
    unordered_map<int, node*> mp;
    int isterminal;
    node(int b){
        this->bin = b;
        isterminal = 0;
    }
};

class trie{
    node* root = new node('-1');
    public:
        void findmaxxor(unordered_map<int, vector<int> > mp)){
            for(auto it : mp){
                vector<int> v = it.second;

                node* temp = root;     // inserted the vector of binaries
                for(int i=0; i<v.size(); i++){
                    if(temp->mp.count(v[i]) == 0){
                        node* newnode = new node(v[i]);
                        temp->mp[v[i]] = newnode;
                        temp = newnode;
                    }
                    else{
                        temp = temp[v[i]];
                    }
                }
                auto itsecond = it++;
                vector<int> v2 = itsecond.second;
                temp = root;
                for(int i=0; i<v2.size(); i++){
                    
                }
            }
            vector<int> v = mp[]
            
        }
};

int main(){
    int n;
    cin >> n;
    int arr[n];
    int maxim = 0;
    unordered_map<int, vector<int>> input;
    for(int i=0; i<n; i++){                     // taking individual nos
        cin >> arr[i];
        if(arr[i] > maxim){
            maxim = arr[i];
        }
    }

    int maxdigits = 0;                          // finding the max binary digits among input nos
    while(maxim!=0){
        maxim = maxim/2;
        maxdigits++;
    }

    for(int i=0; i<n; i++){                     // converting each integers into binary and adding the extra 0s
        int temp = arr[i];
        while(temp!=0){
            input[arr[i]].push_back(temp%2);
            temp = temp/2;
        }
        int diff = maxdigits - input[arr[i]].size();
        for(int j=0; j<diff; j++){
            input[arr[i]].push_back(0);
        }
        reverse(input[arr[i]].begin(), input[arr[i]].end());
    }

    for( auto it : input){                      // printing it out
        cout << it.first << ": ";
        for(auto num : it.second){
            cout << num << " ";
        }
        cout << endl;
    }
    // findmaxxor(arr);
}