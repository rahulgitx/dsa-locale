#include <iostream>
#include <vector>
#include <queue>

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


// treenode<int>* insertTree()
// {
//     int data;
//     cout << "Enter the data for root node: ";
//     cin >> data;
//     treenode<int>* root = new treenode<int>(data);
//     queue< treenode<int>* > q;
//     q.push(root);
//     while(!q.empty())
//     {
//         treenode<int>* front = q.front();
//         q.pop();
//         cout << "How many children are there of " << front->data << " node?" << endl;
//         int n;
//         cin >>n;
//         for (int i=0; i<n; i++)
//         {
//             cout << "Enter the data for child: " << i+1 << endl;
//             cin >> data;
//             treenode<int>* child = new treenode<int>(data);
//             front->children.push_back(child);
//             q.push(child);
//         }
//     }
//     return root;
// }
int maximum(vector<int> v)
{
    int greatest = v[0];
    for (int i=0; i < v.size(); i++)
    {
        if (v[i] > greatest)
        {
            greatest = v[i];
        }
    }
    return greatest;
}
int heightofTree(treenode<int>* root)
{
    // static int height=1;
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.empty())
    {
        return 1;
    }
    vector<int> options;
    for (int i=0; i < root->children.size(); i++)
    {
        int temp = heightofTree(root->children[i]);
        options.push_back(temp);
    }
    return maximum(options) + 1;

}

void printTree(treenode<int>* root)
{
    if (root == NULL)
    {
        cout << "NULL" << endl;
    }
    cout << root->data << " : ";
    for (int i=0; i < root->children.size(); i++)
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
    treenode<int>* root = new treenode<int>(1);
    treenode<int>* node2 = new treenode<int>(2);
    treenode<int>* node3 = new treenode<int>(3);
    treenode<int>* node4 = new treenode<int>(4);
    treenode<int>* node5 = new treenode<int>(5);
    treenode<int>* node6 = new treenode<int>(6);
    treenode<int>* node7 = new treenode<int>(7);
    treenode<int>* node8 = new treenode<int>(8);
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    node2->children.push_back(node5);
    node2->children.push_back(node6);
    node5->children.push_back(node7);
    node7->children.push_back(node8);
    
 
    // treenode<int>* root = insertTree();
    printTree(root);
    int height = heightofTree(root)-1;
    cout << "height of tree : " << height << endl;
    // vector<int> h;
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(3);
    // h.push_back(4);
    // h.push_back(5);
    // int a = maximum(h);
    // cout << "maximum  " << a << endl;
}