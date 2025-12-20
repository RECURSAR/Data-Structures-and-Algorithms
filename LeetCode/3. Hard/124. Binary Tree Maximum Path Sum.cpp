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

// Passing sum as a reference using & so that any changes made to maxi will update sum
int dfs(TreeNode* root, int& maxi) {
    if (root == NULL)
            return 0;
            
    // max of 0 and leftSum or rightSum is taken to exclude the negative path from the path sum to get maximum path
    int leftSum = max(0, dfs(root->left, maxi));
    int rightSum = max(0, dfs(root->right, maxi));

    maxi = max(maxi, leftSum + rightSum + root->val);

    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root){
    int sum = INT_MIN;
    dfs(root, sum);
    return sum;
}

int main() {
    vector<int> list = {1, 2, 3};
    TreeNode* root = createBinaryTree(list);
    int maxSum = maxPathSum(root);
    cout << maxSum << endl;

    return 0;
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