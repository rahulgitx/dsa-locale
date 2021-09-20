#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int m, int n){
    int i=0, j=0, k=0;
    while(i<m && j<n){
        if (arr1[i] < arr2[j]){
            if (i == m-1){
                cout << arr1[i] << " " << arr2[j];
                i++; j++;
            }
            else{
                cout << arr1[i] << " ";
                i++;
            }
        }
        else if( arr1[i] > arr2[j]){
            if (j == n-1){
                cout << arr2[j] << " " << arr1[i] << " " ;
                j++; i++;
            }
            else{
                cout << arr2[j] << " ";
                j++;
            }
            
        }
        else{
            cout << arr2[j] << " " << arr1[i] << " " ;
            i++; j++;
        }
    }
    cout << endl;
}

void mergesort(int arr[], int m){
    int mid = m/2;
    if (mid >= 1){
        int arrleft[mid];
        for (int i=0; i<mid; i++){
            arrleft[i] = arr[i];
        }
        int arrright[m-mid];
        for (int i=mid; i<m; i++){
            arrright[i]=arr[i];
        }
        mergesort(arrleft, sizeof(arrleft)/sizeof(arrleft[0]));
        mergesort(arrleft, sizeof(arrleft)/sizeof(arrleft[0]));

    }
    else{
        
    }

}


int main()
{
    int arr1[3] = {1, 5, 9};
    int arr2[4] = {2, 7, 11};
    // merge(arr1, arr2, 3, 4);
    int arr[8] = { 4, 3, 9, 7, 8, 1, 6, 2};
    mergesort(arr, 8);

}