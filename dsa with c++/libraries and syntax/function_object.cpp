#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = { 4,2,5,2,6,5,7,8};
    sort(arr, arr+5, greater<int>());
    for (int i=0; i<8; i++)
    {
        cout << arr[i] << " ";
    }
}