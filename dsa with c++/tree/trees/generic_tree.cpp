#include <iostream>
#include <vector>

using namespace std;

template <class T>
class treenode{
    public:
        T data;
        vector< treenode<T>* > children;
        treenode(T data)
        {
            this->data = data;
        }
};


treenode<int>* insertTree()
{
    int data;
    cout << "Enter the value of the node: ";
    cin >> data;
    treenode<int>* root = new treenode<int>(data);
    // root->data = data;
    cout << "\n\nEnter the no of children of the node" << root->data ;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        root->children.push_back(insertTree());
    }
    return root;

}

void printTree(treenode<int>* root)        // a better code of printing in depth_of_node
{
    if (root == NULL)
    {
        cout << "NULL" << endl;
    }
    cout << root->data << " : ";
    for (int i=0; i<root->children.size(); i++)
    {
        cout << root->children[i]->data <<", ";
    }
    cout << endl;
    for (int i=0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    // treenode<int>* root = new treenode<int>(1);
    // treenode<int>* node1 = new treenode<int>(2);
    // treenode<int>* node2 = new treenode<int>(3);
    // treenode<int>* node3 = new treenode<int>(4);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);
 
    treenode<int>* root = insertTree();
    printTree(root);

}