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

void preorder(node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{

    /*
               1
              /\
             2  3
            /\  /\
           4 5  6 7
    */
   
   node* root = new node(1);
   root->left = new node(2);
   root->right = new node(3);
   root->left->left = new node(4);
   root->left->right = new node(5);
   root->right->left = new node(6);
   root->right->right = new node(7);

   preorder(root);
}