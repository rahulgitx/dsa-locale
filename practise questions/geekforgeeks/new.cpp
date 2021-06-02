#include <iostream>

using namespace std;

int subarraySum(int arr[], int n, int s)
{
        // Your code here
        cout<<"n : "<<n << " s :"<<s<<"\n";
        int fp, lp;
        /*for(int i=0; i<n; i++)
        {
            //cout << "\narr" <<i<< " "<<arr[i] <<"\n";
            int sum=0;
            for(int j=0; j<=i; j++)
            {
                arr//cout << "\n for i = " <<i<< " "<<" j = "<<j<<"\n";
            }
        }*/
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum=sum+arr[j];
                if (sum==s)
                {
                   fp=i;
                   lp=j;
                   goto output;
                }
            }
        }
        output:
        {
             cout<<"fp "<<fp+1<<" "<<"lp "<<lp+1;
        }
        
        
}       


int main()
{
    int N, S;
    cout << "enter N : ";
    cin >> N;
    cout << "\nenter S : ";
    cin >> S;
    int arr[N];
    cout<<"\n";
    for(int k=0; k<N; ++k)
    {
        cout<<"enter element "<<k+1<<"  ";
        cin>>arr[k];
        cout<<"\n";
    }
    cout<<"done\n";
    subarraySum(arr, N, S);
 

}