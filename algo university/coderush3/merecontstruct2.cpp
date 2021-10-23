#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, c;
    cin >> n;
    cin >> m;
    cin >> c;
    int s[n];
    for (int i=0; i<n; i++){
        cin >> s[i];
    }
    int carr[c][3];
    for (int i = 0; i<c; i++){
        for (int j=0; j<3; j++){
            cin >> carr[i][j];
        }
    }
    map<int, int> mym;
    for (int i=0; i<n; i++){
        mym[i+1] = s[i];
    }
    int atemp, btemp, xtemp;
    for(int i=0; i<c; i++){
        atemp = carr[i][0];
        btemp = carr[i][1];
        xtemp = carr[i][2];
        int amin = mym[atemp];
        if(amin + xtemp > mym[btemp]){
            mym[btemp] = amin + xtemp;
        }

    }

    map<int, int>::iterator it;
    for(it=mym.begin(); it!=mym.end(); it++){
        cout << it->second << endl;
    }
}