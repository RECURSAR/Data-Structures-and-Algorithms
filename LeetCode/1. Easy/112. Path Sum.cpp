#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(const vector<int>& values);
void printBinaryTree(TreeNode* root);
bool hasPathSum(TreeNode* root, int targetSum);

int main() {
   vector<int> list = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
   TreeNode* root = createBinaryTree(list);

   hasPathSum(root, 22) ? cout<<"True" : cout<<"False";

   return 0;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    // Base case: if the root is None, there's no path, return False
    if(root==NULL)
        return false;
    
    // Subtract the current node's value from the target sum
    targetSum = targetSum - root->val;

    // If it's a leaf node and the target sum is now 0, we've found a path
    if(root->left == NULL && root->right == NULL && targetSum== 0)
        return true;

    // Recursively check the left and right subtrees
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// Helper Function to create a binary tree from a level-order input
TreeNode* createBinaryTree(const vector<int>& values) {
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
void printBinaryTree(TreeNode* root) {
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