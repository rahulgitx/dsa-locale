#include <bits/stdc++.h>
using namespace std;


int getNumberOfStudents(vector<int>& A, long long mid){
    long long sum = 0;
    int numberOfStudents=1;
    for(int i=0; i<A.size(); i++){
        if(A[i]+sum > mid){
            numberOfStudents++;
            sum = A[i];
        }
        else{
            sum += A[i];
        }
    }
    return numberOfStudents;
}
int books(vector<int> &A, int B) {
    long long high = 0;
    int low = INT_MIN;
    for(int i=0; i<A.size(); i++){
        low = max(low, A[i]);
        high += A[i];
    }
    int res;
    
    while(low <= high){
        long long mid = low + (high-low)/2;

        
        // find number of students needed for mid to be maximum number of pages one can have
        int numberOfStudents = getNumberOfStudents(A, mid);
        cout << "mid:" << mid << " students:" << numberOfStudents << endl;
        if(numberOfStudents > B){
            low = mid+1;
        }
        else{
            res = mid;
            high = mid-1;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> n;

    cout << "Anser:" << books(v,n);
}

/*
4
12 34 67 90
2
*/