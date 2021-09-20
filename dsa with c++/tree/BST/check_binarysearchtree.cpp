#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int a)
    {
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

int isbst(node* root)
{
    static node* prev=NULL;
    if (root==NULL)
    {
        return 1;
    }
    else
    {
        if( isbst(root->left) )
        {
            if (prev!=NULL && prev->data >= root->data)
            {
                return 0;
            }
            prev = root;
            return isbst(root->right);
        }
        else
        {
            return 0;
        }
    }

    // static node *prev = NULL;
    // if(root!=NULL){
    //     if(!isbst(root->left)){
    //         return 0;
    //     }
    //     if(prev!=NULL && root->data <= prev->data){
    //         return 0;
    //     }
    //     prev = root;
    //     return isbst(root->right);
    // }
    // else{
    //     return 1;
    // }
}

int main()
{
    /*                       8
                             /\
                            /  \
                           6    10
                           /\    /\
                          5  7  9  11
     */
    
    //creating nodes
    node* root = new node(8);
    node* node6 = new node(6);
    node* node10 = new node(10);
    node* node5 = new node(5);
    node* node7 = new node(7);
    node* node9 = new node(9);
    node* node11 = new node(11);
 
    //linking nodes
    root->left = node6;
    root->right = node10;
    
    node6->left = node5;
    node6->right = node7;

    node10->left = node9;
    node10->right = node11;

    // cout << root->left->left->data;

    cout << "Checking if binary tree" << endl;
    int check = isbst(root);
    cout << check << endl;
    if(check==1)
    {
        cout << "Given tree is a binary search tree";
    }
    else
    {
        cout << "Not a binary search tree";
    }

}