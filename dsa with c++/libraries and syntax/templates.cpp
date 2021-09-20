#include <iostream>

using namespace std;

template <class T>
class vctr
{
    public:
        int size;
        T * arr;
        vctr(int m)
        {
            size=m;
            arr = new T[size];
            
        }
        void display()
        {
            for (int i=0; i<size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        T dotproduct(vctr v)
        {
            T sum=0;
            for (int i=0; i<size; i++)
            {
                sum+=this->arr[i]*v.arr[i];
            }
            return sum;
        }
};

int main() 
{
    vctr<float> v1(3);
    v1.arr[0]=3.1;
    v1.arr[1]=4.4;
    v1.arr[2]=6.2;
    v1.display();
    
    vctr<float> v2(3);
    v2.arr[0]=4.9;
    v2.arr[1]=1.4;
    v2.arr[2]=6.3;

    cout << "dot product " << v1.dotproduct(v2) << endl;
     
}