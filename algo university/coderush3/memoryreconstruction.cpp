#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;



void reconstr(int x, int y, int a, int b){
    if(b >= x){
        cout << 0;
        return;
    }
    int count = 0;
    vector<pair<int, int>> v;
    for (int i=a; i<=x; i++){
        for(int j=b; j<i && j<=y; j++){
            v.push_back(make_pair(i, j));
            count++;
            // cout << i << " " << j << endl;
        }
    }
    cout << count << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}
int main(){
    int x, y, a, b;
    cin >>x;
    cin >> y;
    cin >>a;
    cin >> b;
    reconstr(x,y,a,b);
}

// void memreconst(int x, int y, int a, int b){
//     // if(a<b){
//     //     cout << 0;
//     //     return;
//     // }
//     int count =0;

//     priority_queue<pi, vector<pi>, greater<pi>> pq;
//     for(int j=b; j<=y; j++){
//         for(int i=j+1; i<=x; i++){
//             if(i>j){
//                 count++;
//                 // cout << i << " " << j << endl;
//                 pq.push(make_pair(i,j));
//             }
//         }
//     }
//     cout << count << endl;
//     pair<int, int> top;
//     while(!pq.empty()){
//         top = pq.top();
//         pq.pop();
//         cout << top.first << " " << top.second << endl;
//     }
//     // for (int i=0; i<v.size(); i++){
//     //     cout << v[i].first << " " << v[i].second << endl;
//     // }
// }
