#include <bits/stdc++.h>
using namespace std;

int mintimerequired(vector<int> jobs, int k){
    int t = 0;
    for(int i=0; i<jobs.size(); i++){
        t += jobs[i];
        // cout << jobs[i];
    }
    cout << " t : " << t << endl;
    int maxtime = INT_MAX;
    int rt = t, lt = 0;
    int last = 0;
    while(t != last){
        int now = 1, wt = 0;
        int maxim = 0;
        for(int i=0; i<jobs.size(); i++){
            if(wt+jobs[i] > t){
                wt = jobs[i];
                now++;
            }
            else{
                wt += jobs[i];
                if(maxim < wt){
                    maxim = wt;
                }
            }
            cout << "wt: " << wt << " " ;
        }
        last = t;
        cout << endl << "maxim: " << maxim << " now: " << now << endl;
        if(now < k){
            rt = t;
            t = (t+lt)/2;
        }
        else if(now > k){
            lt = t;
            t = (t+rt)/2;
        }
        else{
            rt = t;
            t = (t+lt)/2;
        }
        cout <<  " t: " << t << " rt: " << rt << " lt: " << lt << " last: " << last ;
        // cout << endl << endl;

        if(maxtime > maxim){
            if(now <= k){
                maxtime = maxim;
            }
        }
        cout << "  maxtime: " << maxtime ;
        cout << endl << endl;
    }
    return maxtime;
} 

int main(){
    int k, n;
    cin >> n >> k;
    vector<int> jobs;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        jobs.push_back(temp);
    }

    cout << "answer: " << mintimerequired(jobs, k);
}

/*
5 2
1 2 4 7 8 
*/

/*
6 4
10 7 8 12 6 8
*/