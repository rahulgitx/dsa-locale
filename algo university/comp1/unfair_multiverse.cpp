#include <iostream>
#include <vector>

using namespace std;

class subarr {
    vector<int> arr;
};

int main()
{
        long long n;
        cin >> n;
        long long arr[n];
        for (int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        long nos = (n*(n-1)/2);
        vector<subarr> v(nos);
        int k=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                subarr a;
                a.arr.push_back()
            }
        }
}