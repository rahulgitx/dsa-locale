#include <iostream>
using namespace std;

int * merge(int* a, int* b, int m, int n){
    int *c = new int[m+n];
    int i=0, j=0, k=0;
    while(i<m || j<n){
        if((*(a+i) < *(b+j)) && (i<m) && (j<n)){
            *(c+k) = *(a+i);
            k++;
            i++;
        }
        if((*(a+i) >= *(b+j)) && (j<n) && (i<m)){
            *(c+k) = *(b+j);
            k++; j++;
        }
        if((i==m) && (j<n)){
            *(c+k) = *(b+j);
            j++; k++;
        }
        if((j==n) && (i<m)){
            *(c+k) = *(a+i);
            i++; k++;
        }
    }
    
    return c;
}

int* mergesort(int* arr, int f, int l){
    if (f<l){    
        int mid = (f+l)/2;
        int *a = mergesort(arr, f, mid);
        int *b = mergesort(arr, mid+1, l);
        int m = mid - f + 1;
        int n = l - mid + 1; 
        return merge(a, b, m, n);
    }
    else{
        int *endcase = new int {*(arr+f)};
        return endcase;
    }    
}


int main()
{
    int m=3, n=3;
    int *arr1 = new int[m] {6,4,2};
    int *arr2 = new int[n] {7,3,1};
    int* c = merge(arr1, arr2, 3, 4);
    for (int i=0; i<(m+n); i++){
        cout << *(c+i) << " ";
    }
    cout << endl;
    
    // int x = 8;
    // int *arr = new int[x] {4, 3, 9, 7, 8, 1, 6, 2};
    // int mid = x/2;
    // int f = 0, l = x-1;
    // int *output = mergesort(arr,f, l);
    // for (int i=0; i<(x); i++){
    //     cout << *(output+i) << " ";
    // }

}