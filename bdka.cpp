#include <iostream>
#include <vector>

using namespace std;

void myf(int* arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int ret(int num){
    while(num>0){
        return (num+ret(num-2));
    }
    return num;
}

void func(void);
static int count = 5;


int main(){
 

    // unsigned int y = 2;
    // int x = -2;
    // if(x>y){
    //     cout << "x is greater than y";
    // }
    // else{
    //     cout << "y is greater than x";
    // }
    
    while(count--){
        func();
    }    
    return 0;

    
}

void func(void){
    static int i=5; i++;
    cout << "1 is " << i << " and count is " << count << endl;
}