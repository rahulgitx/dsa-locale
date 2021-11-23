#include <bits/stdc++.h>
using namespace std;

struct  node{
    int bit;
    unordered_map<long long, node*> mp;
    long long onthispath;
    bool isterminal;
    node(int b){
        this->bit = b;
        this->isterminal = false;
        this->onthispath = 0;
    }
};

class trie{
    public:
        node *root = new node(-1);
        void insertxor(long long n){
            // cout << "inserting for : " << n << endl;
            node *temp = root;
            for(int i=63; i>=0; i--){
                int cb = 1&(n >> i) ? 1 : 0;
                // cout << cb << " ";
                if(temp->mp.count(cb) == 0){
                    node *newnode = new node(cb);
                    temp->mp[cb] = newnode;
                    temp = temp->mp[cb];
                }
                else{
                    temp = temp->mp[cb];
                }
                temp->onthispath++;
            }
            temp->isterminal = true;
            // cout << endl;
        }

        long long subxorlessk(long long n, long long k){
            node *temp = root;
            long long totalnodes = 0;
            for(int i=63; i>=0; i--){
                int cb = 1&(n>>i) ? 1 : 0;
                int kb = 1&(k>>i) ? 1 : 0;
                // cout << "kb: " << kb;
                // cout << " cb: " << cb << " i: " << i << endl;
                if(kb == 0){
                    if(temp->isterminal){
                        return totalnodes;
                    }
                    else{
                        if(cb == 1){
                            if(temp->mp.count(1) != 0){            // there is 1   
                                // cout << "there was a 1 ";
                                temp = temp->mp[1];                 // even if there is also 0 we don't have to see for it
                            }
                            else{                                   // there is no 1
                                return totalnodes;                  // we cannot see for 0
                            }
                        }
                        else{         // cb == 0
                            if(temp->mp.count(0) != 0){              // there is 0
                                temp = temp->mp[0];                 // even if there is 1 we don't want to see it
                            }
                            else{                                   // there is no 0
                                return totalnodes;                  // no point of seeing 1
                            }
                        }
                    }
  
                }
                else{         // kb == 1
                    if(cb == 1){
                        if(temp->mp.count(1) != 0){       // there is 1
                            totalnodes += temp->mp[1]->onthispath;
                            // cout << endl << "incremented at there is 1 " << endl;
                            if(temp->mp.count(0) == 0){
                                return totalnodes;               // there is 1 but no 0
                            }
                            else{                          
                                if(temp->mp[0]->isterminal){
                                    return totalnodes;
                                }
                                else{
                                    temp = temp->mp[0];              // there is 1 and also 1
                                }
                            }
                        }
                        else{    
                            if(temp->mp[0]->isterminal){
                                return totalnodes;
                            }  
                            else{
                                temp = temp->mp[0];
                            }                          // no 1

                        }
                    }
                    else{           // cb == 0
                        if(temp->mp.count(0) != 0){    // there is 0
                            totalnodes += temp->mp[0]->onthispath;
                            // cout << endl << "incremented at there is 0 " << endl;
                            if(temp->mp.count(1) == 0){        // there is 0 but not 1
                                return totalnodes;
                            }
                            else{                               // there is 0 but also 1
                                if(temp->mp[1]->isterminal){
                                    return totalnodes;
                                }
                                else{
                                    temp = temp->mp[1];
                                }
                            }
                        }
                        else{                  // there is no 0
                            if(temp->mp[1]->isterminal){
                                return totalnodes;
                            }
                            else{
                                temp = temp->mp[1];
                            }

                        }
                    }
                }

            }
            return totalnodes;
        }
};

long long maxxorlessthank(vector<long long> arr, long long k){
    vector<long long> prefarr;
    long long prev = arr[0];
    prefarr.push_back(arr[0]);
    int s = arr.size();
    for(int i=1; i<s; i++){
        prefarr.push_back(prev^arr[i]);
        prev = arr[i]^prev;
    }
    // cout << "prefarr: ";
    // for(int i=0; i<arr.size(); i++){
        // cout << prefarr[i] << " ";
    // }
    // cout << endl << endl;

    long long countlessk = 0;
    if(prefarr[0] < k){
        countlessk++;
    }

    trie t;
    t.insertxor(prefarr[0]);
    // cout << "0: countlessk: " << countlessk << endl;
    int ps = prefarr.size();
    for(int i=1; i<ps; i++){
        // cout << arr[i] << ">/<" << k << endl;
        if(prefarr[i] < k){
            countlessk++;
            // cout << "incremented in prefarr itself for i: " << i << " arr[i] " << arr[i] << " and k: " << k << endl;
        }
        countlessk += t.subxorlessk(prefarr[i], k);
        t.insertxor(prefarr[i]);
        // cout << i << ": " << "countlessk: " << countlessk << endl;
    }

    return countlessk;

}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> input;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        input.push_back(temp);
    }
    cout << maxxorlessthank(input, k);
}


/*
3 4
4 2 1
ans=3
*/


/*
5 3
8 9 10 11 12
ans=3
*/

/*
5 7
16 16 1 13 7
ans=3
*/

/*
76 19
50 45 86 32 40 70 15 79 27 61 24 19 34 44 72 88 84 25 72 32 99 36 25 4 40 92 25 67 19 40 18 68 85 55 52 76 76 66 6 55 78 30 73 11 25 97 99 8 73 22 91 71 57 15 74 48 7 50 14 25 42 83 45 78 89 96 53 17 61 58 71 90 39 95 100 15 43 67
*/

/*
5 8
12 4 6 8 21
ans=4
*/