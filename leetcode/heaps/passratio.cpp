#include <bits/stdc++.h>
using namespace std;

 double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    vector<int> v;
    int a,b, mark;
    double tempearlier, temp, tempdiff, maxdiff = 0.000, max;
    for(int i=0; i<classes.size(); i++){
        a = classes[i][0];
        b = classes[i][1];
        tempearlier = (double)a/(double)b;
        temp = ((double)a+(double)extraStudents)/((double)b+(double)extraStudents);
        tempdiff = temp - tempearlier;
        cout << "temp: " << temp << "   tempdiff: " << tempdiff <<endl;
        v.push_back(temp);
        if(tempdiff > maxdiff){
            maxdiff = tempdiff;
            max = temp;
            mark = i;
        }
    }
    cout << "max: " << max << endl;
    double total = 0.0;
    for(int i=0; i<classes.size(); i++){
        if(i == mark){
            total += max;
        }
        else{
            cout << "added" << " " << (double)classes[i][0]/(double)classes[i][1] << " ";
            total += (double)classes[i][0]/(double)classes[i][1];
        }
        cout << "total: " << total << endl;
    }
    double avg = total/classes.size();
    return avg;
}


int main(){
    vector<vector<int>> v 
    {
        {{2,4},
        {3,9},
        {4,5},
        {2,10}}
    };
    int k = 4;
    double output = maxAverageRatio(v, k);
    cout << output;
}