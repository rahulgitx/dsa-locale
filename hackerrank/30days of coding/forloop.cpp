#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    for(int n=a; n<=b; n++)
    {
        if(1<=n && n<=9){
            if(n==1){
                printf("one\n");
            }
            if(n==2){
                printf("two\n");
            }
            if(n==3){
                printf("three\n");
            }
            if(n==4){
                printf("four\n");
            }
            if(n==5){
                printf("five\n");
            }
            if(n==6){
                printf("six\n");
            }
            if(n==7){
                printf("seven\n");
            }
            if(n==8){
                printf("eight\n");
            }
            if(n==9){
                printf("nine\n");
            }
        }
        else{
            if(n%2==0){
                printf("even\n");
            }
            else{
                printf("odd\n");
            }
        }
    }
    return 0;
}