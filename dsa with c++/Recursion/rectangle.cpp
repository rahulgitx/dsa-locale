#include <bits/stdc++.h>
using namespace std;

vector<int> func(int area){
        int lastlimit = pow(area, 0.5);
        // cout << lastlimit;
        int min = INT_MAX;
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        int mindiff = INT_MAX;
        int b, l;
        for(int i=1; i<=lastlimit; i++){
            if(area%i == 0){
                b = i;
                l = area/b;
                if(mindiff > l-b){
                    mindiff = l-b;
                    v[0] = l;
                    v[1] = b;
                }
            }
        }
        return v;
}

int main(){
    vector<int> v(3);
    for(int i=0; i<3; i++) cout << v[i] << " ";
}