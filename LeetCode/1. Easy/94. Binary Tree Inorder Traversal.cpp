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

// Simple inorder traversal
/*
TreeNode* traverse(TreeNode* root, vector<int> &traversal){
    if(root == NULL)
        return NULL;

    TreeNode *lst = traverse(root->left, traversal);
    traversal.push_back(root->val);
    TreeNode *rst = traverse(root->right, traversal);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;
    traverse(root, traversal);
    return traversal;        
}
*/

// Inorder using Morris Traversal
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> inorder;
    TreeNode *current = root;

    // Traverse the tree
    while(current) {
        // Case 1: If current has no left child, add it to result and move to right child
        if(current->left == NULL) {
            inorder.push_back(current->val);  // No left subtree, so process current node
            current = current->right;         // Move to right subtree
        } 
        // Case 2: If current has a left child
        else {
            TreeNode *prev = current->left;   // Find the predecessor of current node (rightmost node of left subtree)
            
            // Find the rightmost node in left subtree or connect it to the current node
            while(prev->right && prev->right != current) {
                prev = prev->right;           // Keep moving right
            }

            // Case 2a: If the rightmost node's right is NULL, connect it to current
            if(prev->right == NULL) {
                prev->right = current;        // Create a thread to return to current after left subtree traversal
                current = current->left;      // Move to left subtree
            } 
            // Case 2b: If the rightmost node's right already points to current (thread exists), break it
            else {
                prev->right = NULL;           // Restore tree structure (remove the thread)
                inorder.push_back(current->val);  // Process current node after left subtree
                current = current->right;     // Move to right subtree
            }
        }
    }

    return inorder;
}

int main() {
    vector<int> list = {1,-1,2,3};
    TreeNode* root = createBinaryTree(list);

    vector<int> traversal = inorderTraversal(root);

    for(auto traverse: traversal)
        cout<<traverse;

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