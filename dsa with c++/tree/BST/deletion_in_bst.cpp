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

void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node* inorderpredecessor(node* root)
{
    // if (root->left = NULL)
    // {
    //     root = root
    // }
    root = root->left;
    while( root->right != NULL)
    {
        root = root->right;
    }
    return root;
}


node* deletenode(node* root, int val)
{
    if (root = NULL)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root = deletenode(root->left, val);
    }
    else if (val > root->data)
    {
        root = deletenode(root->right, val);
    }
    else
    {
        if ( root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            root = root->right;
            root->right = deletenode(root->right, root->data);
        }
        else if ( root->right == NULL)
        {
            root = root->left;
            root->left = deletenode(root->left, root->data);
        }
        else
        {
            root = root->left;
            root->left = deletenode(root->left, root->data);
        }
    }
    return root;
}

int main()
{
        /*                    80
                             /  \
                            /    \
                           60    100
                          / \       \
                        50  70      110
     */
    
    //creating nodes
    node* root = new node(80);
    node* node6 = new node(60);
    node* node10 = new node(100);
    node* node5 = new node(50);
    node* node7 = new node(70);
    // node* node9 = new node(90);
    node* node11 = new node(110);
 
    //linking nodes
    root->left = node6;
    root->right = node10;
    
    node6->left = node5;
    node6->right = node7;

    // node10->left = node9;
    node10->right = node11;

    // node* pre = inorderpredecessor(root->right);
    // cout << pre->data;
    deletenode (root, 110);
    inorder(root);

    
    
}