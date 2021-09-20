#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int> &stack);
void display(vector<int> stack);
void pop(vector<int> &stack);


int top = -1;


int main()
{
    vector<int> stack;
    char c='y';
   
    char option;
    while (true)
    {
        cout << "Press: \n'p' to pop \n'i' to insert more  \n'd' to display the stack \n'e' to exit \n";
        cin >> option;
        if (option=='d')
        {
            display(stack);
        }
        if (option=='p')
        {
            pop(stack);
        }
        if (option=='e')
        {
            return 0;
        }
        if (option == 'i')
        {
            insert(stack);
        }
    }
    
}

void insert(vector<int> &stack)
{
    char c='y';
    int ele;
    while (c=='y')
    {
        cout << "Insert the element: ";
        cin >> ele;
        cout << "Inserting the element..." << endl;
        stack.push_back(ele);
        top++;
        cout << "Element inserted. Want to insert more? ";
        cin >> c;

    }
    // while (cin >> ele)
    // {
    //     cin >> ele;
    //     stack.push_back(ele);
    // }
}

void display(vector<int> stack)
{
    int dtop = top;
    while(dtop>=0)
    {
        cout << stack[dtop] << " ";
        dtop--;
    } 
    cout <<endl;
}

void pop(vector<int> &stack)
{
    char c='y';
    while(c == 'y')
    {
        cout << "Element popped: " << stack[top] << endl;
        top--;
        cout << "want top pop more? ";
        cin >> c;

    }
    
}