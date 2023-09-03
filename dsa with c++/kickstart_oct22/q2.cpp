#include <bits/stdc++.h>
using namespace std;

class scorepair{
    public:
        float s;
        int t;
};


float dist(int x, int y){
    return sqrt(pow(x,2)+pow(y,2));
}
int main(){
    int t;
    cin >> t;
    int c = 1;
    while(c <= t){
        int rs, rh;
        cin >> rs >> rh;
        int n;
        cin >> n;
        vector<pair<float, char>> v;
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            pair<float, char> t;
            float d = dist(x,y);
            cout << "d:" << d << endl;
            if(d-rs <= rh){
                cout << "inserted" << endl;
                t.first = d;
                t.second = 'r';
                v.push_back(t);
            }
        }
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            int x, y;
            cin >> x >> y;
            pair<float, char> t;
            float d = dist(x,y);
            if(d-rs <= rh){
                t.first = d;
                t.second = 'r';
                v.push_back(t);
            }
        }

        sort(v.begin(), v.end());
        int r = 0, y = 0;
        char last;
        if(v.size() == 0){
            cout << "Case #" << c<< ": " << 0 << " " << 0 << endl;
            c++;
            continue;
        }
        last = v[0].second;
        for(int i=0; i<v.size(); i++){
            if(v[i].second == last){
                cout << v[i].second << ":" << v[i].first << endl;
                if(v[i].second == 'r'){
                    r++;
                }
                else{
                    y++;
                }
            }
            else{
                break;
            }
        }

         cout << "Case #" << c<< ": " << r << " " << y << endl;
         c++;
    }
}