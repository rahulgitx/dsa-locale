#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]) - 1;
    // cout << n;
    // reversing integer array
    int temp;
    for (int i=0; i<(n/2); i++)
    {
        temp = arr[i];
        arr[i] = arr[n-i];
        arr[n-i] = temp;
    }
    for (int i=0; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //reversing string
    string str = "alqaeda";
    int m = str.length()-1;
    for (int i=0; i<(str.length()/2); i++)
    {
        temp = str[i];
        str[i] = str[m-i];
        str[m-i] = temp;
    }
    cout << str;
}