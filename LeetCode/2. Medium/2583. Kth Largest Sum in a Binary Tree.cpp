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

long long kthLargestLevelSum(TreeNode* root, int k) {
    if (!root)
        return -1;

    // Vector to store the level sums
    vector<long long> levelSums;

    // Queue for BFS traversal
    queue<TreeNode*> q;
    q.push(root);

    // BFS traversal
    while (!q.empty()) {
        int size = q.size();
        long long levelSum = 0;

        // Process all nodes at the current level
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        // Store the sum of this level
        levelSums.push_back(levelSum);
    }

    // If the number of levels is less than k, return -1
    if (levelSums.size() < k)
        return -1;

    // Sort the level sums in descending order and return the k-th largest
    sort(levelSums.begin(), levelSums.end(), greater<long long>());
    return levelSums[k - 1];
}

int main() {
    vector<int> list={5,8,9,2,1,3,7,4,6};
    int k = 2;
    TreeNode* root = createBinaryTree(list);

    cout<<kthLargestLevelSum(root,k);

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