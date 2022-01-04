#include <bits/stdc++.h>
using namespace std;

struct node{
    int colour;
    vector<node*> children;
    node(int c){
        colour = c;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int temp;
    vector<nod*> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v[i] = new node(temp);
    }
    int p, c;
    for(int i=0; i<n-1; i++){
        cin >> p >> c;
        v[p-1].chi
    }
}