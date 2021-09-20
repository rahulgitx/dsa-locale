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

node* search(node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (key == root->data)
        {
            return root;
        }
        if (key < root->data)
        {
            search(root->left, key);
        }
        if (key > root->data)
        {
            search(root->right, key);
        }

    }
}

int main()
{
    /*                        80
                             /  \
                            /    \
                           60    100
                          / \     / \
                        50  70   90  110
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
    node* result = search(root, 90);
    if (result != NULL)
    {
        cout << "Result found" << endl;
    }
    else
    {
        cout << "Result not found" << endl;
    }

 
    

}