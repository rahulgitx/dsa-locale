#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
    
    // int a = 2;
    // int &y=a;
    // int* arr[2];
    // int aoa1[4]={1,2,3,4};
    // int aoa2[3]={2,3,4};
    // // int (&x)[4]=aoa1;
    // // // for (int e:x)
    // // // {
    // // //     cout << e;
    // // // }
    // // cout << endl << x;
    // // cout <<  typeid(x).name();
    // arr[0]=aoa1;
    // arr[1]=aoa2;
    // cout << *(arr[0]+1);


    int n, q, k;
    scanf("%d %d", &n, &q);
    vector<int> v[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k);
        // vector<int> v1(k);
        
        int temp;
        for (int j=0; j<k; j++)
        {
            scanf("%d", &temp);
            v[i].push_back(temp);
        }
    }
    // for (int i=0; i<n; i++)
    // {
    //     cout << "elements at " << i << ": ";
    //     for (auto j=v[i].begin(); j!=v[i].end(); j++)
    //     {
    //         cout << *j << ' ';
    //     }
    //     cout << endl;
    // }
    
    int ans[q][2];
    for (int x=0; x<q; x++)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        ans[x][0]=i;
        ans[x][1]=j;
        // printf("%d and %d", i, j);
        // printf("%d", *(iter+j));
    }
    for (int x=0; x<q; x++)
    {
        vector<int>::iterator iter = v[(ans[x][0])].begin();
        printf("%d\n", *(iter+ans[x][1]));

    }
    return 0;

}