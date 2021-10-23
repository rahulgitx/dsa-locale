#include <iostream>
#include <stack>
using namespace std;

void check(int arr[], int output[], int n){
    stack<int> table;
    int zenobia[n];
    int j=0, i=0;
    while(j<n || i<n){
        if(arr[i] == output[j]){
            zenobia[j] == arr[i];
            i++; j++;
        }
        else{
            if(!table.empty()){
                if (table.top() == output[j]){
                    table.pop();
                    j++;
                }
                else{
                    if(i<n){
                        table.push(arr[i]);
                        i++;
                    }
                    else{
                        break;
                    }
                   
                }
            }
            else if(table.empty()){
                table.push(arr[i]);
                i++;
            }
            // i++;
        }
    }
    if(j<i){
        cout << "i: " << i << " j: " << j << endl;
        cout << "NO" << endl;
    }
    else{
        cout << "i: " << i << " j: " << j << endl;
        cout << "YES" << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){          // for yes: 10 10 1 9 6 5 4 2 8 3 7   || for no: 10 7 6 2 5 3 4 8 10 4 9
        cin >> arr[i];
    }
    int output[n] =  {6,2,7,4,5,8,3,10,9,4}; //{9,5,6,1,2,4,10,7,3,8};
    check(arr, output, n);
    
    // stack<int> s;
    // int a = 5;
    // cout << (a == s.top());
}
