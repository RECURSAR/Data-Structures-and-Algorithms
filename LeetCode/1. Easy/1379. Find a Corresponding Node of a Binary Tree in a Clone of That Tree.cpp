#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(const vector<int>& values);
void printBinaryTree(TreeNode* root);
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);

int main()
{
    vector<int> list = {7,4,3,-1,-1,6,19};
    TreeNode *original = createBinaryTree(list);
    TreeNode *cloned = createBinaryTree(list);
    TreeNode *target = original->right;
    TreeNode *res = getTargetCopy(original, cloned, target);

    cout<<res->val;

   return 0;
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
    if (original == nullptr) 
        return NULL;
    
    // If the original node matches the target, return the cloned node
    if (original == target) 
        return cloned;
    
    // Recursively search in the left subtree
    TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
    if (leftResult != nullptr) 
        return leftResult;
    
    // Recursively search in the right subtree
    return getTargetCopy(original->right, cloned->right, target);
}

// Helper Function to create a binary tree from a level-order input
TreeNode* createBinaryTree(const vector<int>& values){
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper Function to print the binary tree in level order
void printBinaryTree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null ";
        }
    }
    
    cout << endl;
}