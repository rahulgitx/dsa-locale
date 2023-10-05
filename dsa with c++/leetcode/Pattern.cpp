#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};
class Solution {
public:
    Node* insert(Node* root, int val){
        if(!root){
            Node* node = new Node(val);
            return node;
        }
        if(val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }
    void bfs(Node* root){
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        int count = 0;
        while(!nodeQueue.empty()){
            Node* temp = nodeQueue.front();
            nodeQueue.pop();
            if(temp->left) nodeQueue.push(temp->left);
            if(temp->right) nodeQueue.push(temp->right);
            count++;
        }
        cout << "count of nodes : " << count << endl;
    }
    bool find132patternn(vector<int>& nums) {
        Node* root=nullptr;
        string pattern = "rl";
        bool isPresent = false;
        for(int i=0; i<nums.size(); i++){
            root = insert(root, nums[i]);
        }
        // bfs(root);
        return matchPattern(root, pattern, 0);
    }
    bool matchPattern(Node* root, string& pattern, int index){
        if(!root) return false;
        if(index >= pattern.size()) return true;
        char direction = pattern[index];
        if(direction == 'l'){
            return matchPattern(root->left, pattern, index+1) 
                   || matchPattern(root->right, pattern, 0);
        }
        return matchPattern(root->right, pattern, index+1) 
               || matchPattern(root->left, pattern, 0);
    }
        bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        stack<int> numberStack;
        for(int i=0; i<nums.size(); i++){
            if(numberStack.size()){
                if(nums[i] > numberStack.top()) continue;
                else{
                    if(numberStack.size()>1) return true;
                    numberStack.pop();
                }
            }

            numberStack.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    Solution solution;
    cout << solution.find132pattern(nums);
}

/*
4
1 2 3 4
4
3 1 4 2
*/
