#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a<b;
}

 int kthSmallest(int arr[], int l, int r, int k)
{
        //code here
        
        int current = l;
        int i=0, count=0;
        while( current != r)
        {
            
            current = arr[i];
            i++;
            count++;
            
        }
        sort(arr, arr+count);
        cout << "count : " << count << endl;
        for (int i=0; i<count; i++)
        {
            cout << arr[i] << " ";
        }
        return arr[k-1];
}

int main()
{
    cout << "Enter the no of array" << endl;
    int n;
    cin >>n;
    int arr[n];
    for (int i=0; i<n; i++)       //  9 98 53 61 24 65 89 52 35 67
    {
        cin >> arr[i];
    }
//     sort(arr, arr+n, compare);
//     cout << "Sorted array: " << endl;
//     for (int i=0; i<n; i++)
//     {
//          cout << arr[i] << " ";
//     }

    int output = kthSmallest(arr, arr[0], arr[n-1], 3);
    cout << "output " << output << endl;

    // sort(arr, arr+n, compare);
    // cout << "Sorted array: " << endl;
    // for (int i=0; i<n; i++)
    // {
    //      cout << arr[i] << " ";
    // }
}