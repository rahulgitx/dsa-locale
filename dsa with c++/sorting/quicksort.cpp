#include <iostream>
using namespace std;

void swap(int &a, int &b){
    // a = a^b;
    // b = a^b;
    // a = a^b;
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int h){
    int low = l;
    int high = h;
    int pivot = arr[l];
    h=h+1;
    while(l<h){
        do{
            l++;
        }while(arr[l]<pivot && l<=high);
        do{
            h--;
        }while(arr[h]>pivot && h>=low);
        if(l<h){
            // cout << "arr[f]: " << arr[l] << " arr[l]: " << arr[h] << endl; 
            swap(arr[l], arr[h]);
            // cout << "swap done" << endl;
        }
    }
    // cout << "high: " << h << endl;
    // cout << "arr[high]: " << arr[h] << endl;
    // cout << "arr[low]: " << arr[low] << endl;
    swap(arr[h], arr[low]);
    return h;
}

void quick_sort(int arr[], int f, int l){
    if(f<l){
        // cout << endl << endl;
        // cout << "going for partition: " << endl;
        int j = partition(arr, f, l);
        quick_sort(arr, f, j);
        quick_sort(arr, j+1, l);
    }
}




int main(){
    int n=9;
    int arr[n] = {9,8,7,6,5,4,3,2,1}; //{10,16,18,12,15,6,3,9,5};  // 

    // int newarr[3] = {1,2,3};
    // int output = partition(newarr, 0, 2);
    // for (int i=0; i<3; i++){
    //     cout << newarr[i] << " ";
    // }
    // int output = partition(arr, 0, 8);
    // cout << "output of paritition: " << output << endl;

    quick_sort(arr, 0, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}