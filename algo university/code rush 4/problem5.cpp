#include <bits/stdc++.h>
using namespace std;

void alavara(int a, long long b, int x){
    if(a == 0 && b== 0){
        cout << -1;
        return;
    }
    if(a == 0 && b > 0){
        cout << 0 << " " << 0;
        return;
    }
    long long int no = pow(a,b) + 0.5;
    cout << "no : " << no << endl;
    int nod = 0;
    long long int temp = no;
    while(temp!=0){
        temp = temp/10;
        nod++;
    }
    if(nod < x){
        cout << -1;
        return;
    }
    // cout << "nod: " << nod << endl;
    long long int power = (pow(10,(nod-x))+0.5);
    // cout << " (pow(10,(nod-x)+0.5)) " << (pow(10,(nod-x))+0.5) << endl;
    cout << "power: " << power << endl;
    cout << no/power << " ";
    int count = 1;
    vector<int> ans;
    while(count <= x){
         ans.push_back(no%10);
        no = no/10;
        count++;
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i];
    }
}

int main(){
    int a, x;
    long long b;
    cin >> a >> b >> x;
    alavara(a, b, x);
}

/*
1000 1000 3
*/

/*
1 1 1
*/

/*
1 0 1
*/

/*
5 6 2
*/