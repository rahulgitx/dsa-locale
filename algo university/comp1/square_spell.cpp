#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long pow[n];
    int flag = 0;
    for (int i=0; i<n; i++)
    {
        cin >> pow[i];
    }
    long long greatest = pow[0];
    for (int i=1; i<n; i++)
    {
        
        if (pow[i] > greatest)
        {
            flag = i;
            greatest = pow[i];
        }
        else if (pow[i] < 0)
        {
            int temp = -pow[i];
            if (temp >= greatest)
            {
                greatest = temp;
                flag = i;
            }
        }
    }
    // cout << flag <<endl;
    pow[flag] = pow[flag]*pow[flag];


    long long max = pow[0], currsum = pow[0];
    for (int i=1; i<n; i++)
    {
        if (currsum < 0 && pow[i] < 0)
        {
            if (pow[i] > currsum)
            {
                currsum = pow[i];
            }
        }
        if (currsum < 0 && pow[i] > 0)
        {
            currsum = pow[i];
        }
        else
        {
            currsum += pow[i];
        }

        if (max < 0 && pow[i] > 0)
        {
            max = pow[i];
        }
        if (currsum > max)
        {
            max = currsum;
        }

    }
    cout << max;

}

