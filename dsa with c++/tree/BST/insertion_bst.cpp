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

void insert(node* root, int key)
{
    node* prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Element already exists. Cannot insert more!" << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    node* newnode = new node(key);
    if ( key < prev->data)
    {
        prev->left = newnode;
        cout << "Node inserted on the left!" << endl;
    }
    if ( key > prev->data)
    {
        prev->right = newnode;
        cout << "Node inserted on the right" << endl;
    }
    
}

int main()
{
        /*                    80
                             /  \
                            /    \
                           60    100
                          / \     / \
                        50  70   90  110
     */
    
    // //creating nodes
    // node* root = new node(80);
    // node* node6 = new node(60);
    // node* node10 = new node(100);
    // node* node5 = new node(50);
    // node* node7 = new node(70);
    // node* node9 = new node(90);
    // node* node11 = new node(110);
 
    // //linking nodes
    // root->left = node6;
    // root->right = node10;
    
    // node6->left = node5;
    // node6->right = node7;

    // node10->left = node9;
    // node10->right = node11;
    node* root = new node(80);

    int arr[6]={81, 61, 72, 89, 15, 98};
    // arr = ;
    for (int i=0; i<6; i++)
    {
        insert(root, arr[i]);
    }

    // insert(root, 81);
    // insert(root, 61);
    // insert(root, 72);
    // insert(root, 89);
    // insert(root, 15);
    // insert(root, 98);
    inorder(root);
}