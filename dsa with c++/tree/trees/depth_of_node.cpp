// printing all nodes from a given depth

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class treenode{
    public:
        T data;
        vector<treenode<T>*> children;
        treenode(T data)
        {
            this->data = data;
        }
};

void printTree(treenode<int>* root)
{
    if (root == NULL)
    {
        cout << "NULL: " << endl;
    }
    else
    {
        cout << root->data << " : ";
        for (int i = 0 ; i < root->children.size(); i++)
        {
            if (root->children[i] == NULL)
            {
                cout << "NULL, ";
            }
            else
            {
                cout << root->children[i]->data << ", ";
            }
        }
        cout << endl;
        for (int i = 0; i < root->children.size(); i++)
        {
            printTree(root->children[i]);
        }
    }
}

void depth(treenode<int>* root, int k)
{
    if (k == 0)
    {
        if (root == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << root->data << " ";
        }
    }
    else
    {
        for (int i=0; i < root->children.size(); i++)
        {
            depth(root->children[i], k-1);
        }
    }
}

int main()
{ 
    treenode<int>* root = new treenode<int>(1);
    treenode<int>* node2 = new treenode<int>(2);
    treenode<int>* node3 = new treenode<int>(3);
    treenode<int>* node4 = new treenode<int>(4);
    treenode<int>* node5 = new treenode<int>(5);
    treenode<int>* node6 = new treenode<int>(6);
    treenode<int>* node7 = new treenode<int>(7);
    treenode<int>* node8 = new treenode<int>(8);
    treenode<int>* node9 = new treenode<int>(9);
    treenode<int>* node10 = new treenode<int>(10);
    treenode<int>* node11 = new treenode<int>(11);
    treenode<int>* node12 = new treenode<int>(12);
    treenode<int>* node13 =   NULL;//new treenode<int>(13); // NULL; //
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    node2->children.push_back(node5);
    node5->children.push_back(node6);
    node5->children.push_back(node7);
    node3->children.push_back(node8);
    node8->children.push_back(node9);
    node7->children.push_back(node10);
    node10->children.push_back(node11);
    node11->children.push_back(node12);
    node12->children.push_back(node13);

    // printTree(root); 
    depth(root, 7);

}