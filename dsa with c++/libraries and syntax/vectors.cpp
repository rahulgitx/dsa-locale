#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> v)
{
    for (int i=0; i<v.size(); i++)
    {
        //  printf("%d", v[i]);
         printf("%d ", v.at(i));
    }
    printf("\n");
}
int main(){
    // printf("Hello world");
    int element, size;
    // vector<int> v1;           // this is a zero length vector
    
    // printf("\nEnter the no of elements you want to insert in vector v1: ");
    // scanf("%d", &size);
    // printf("\nsize entered: %d \n", size);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter the value: ");
    //     scanf("%d", &element);
    //     v1.push_back(element);
    // }
    // printf("\nsize of elements: %d\n", v1.size());
    // display(v1);
    // // v1.pop_back();        // will remove the last element of the vector
    // vector<int>::iterator iter = v1.begin();               // declaring a vector
    // v1.insert(iter+1, 5, 488);
    // display(v1);
    vector<float> v2(6);
    vector<float>::iterator iter = v2.begin();
    v2.insert(iter, 5, 488);
    printf("size of v2: %d\n", v2.size());
    display(v2);
    vector<int> v3(4,3.0);
    display(v3);
    vector<int> v4(v3);
    display(v4);
}