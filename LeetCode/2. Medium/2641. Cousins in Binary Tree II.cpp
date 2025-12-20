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

TreeNode* replaceValueInTree(TreeNode* root) {
    if (!root) 
        return root;

    // Step 1: Compute the level sums using BFS
    vector<int> levelSums;  // This stores the sum of each level
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int levelSum = 0;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        levelSums.push_back(levelSum);
    }

    // Step 2: Replace each node's value with the sum of its level minus itself and its sibling
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            int siblingSum = 0;
            if (node->left) siblingSum += node->left->val;
            if (node->right) siblingSum += node->right->val;

            // The new value for the node is the level sum minus its sibling sum
            if (node->left) {
                node->left->val = levelSums[level + 1] - siblingSum;
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = levelSums[level + 1] - siblingSum;
                q.push(node->right);
            }
        }
        level++;
    }

    // Set the root node's value to 0 (as specified in the logic)
    root->val = 0;

    return root;
}

int main() {
    vector<int> list = {5,4,9,1,10,-1,7};
    TreeNode* root = createBinaryTree(list);

    TreeNode *result = replaceValueInTree(root);
    printBinaryTree(result);

    return 0;
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