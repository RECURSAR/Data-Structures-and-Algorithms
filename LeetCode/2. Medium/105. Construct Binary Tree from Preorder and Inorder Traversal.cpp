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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

int main()
{
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    TreeNode *root;

    root = buildTree(preorder, inorder);
    printBinaryTree(root);
    
    return 0;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    if (preorder.empty() || inorder.empty())
            return NULL;

    // The first element in preorder is the root
    TreeNode* root = new TreeNode(preorder[0]);

    // Find the index of the root in inorder
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    int mid = distance(inorder.begin(), it);

    // Creating sublists which will be passed to BuildTree recursively so as to build the left and right subtrees

    /*vector<int> nigger(a, b) initializes a vector of size a with the value b.
    vector<int> vec(iterator1, iterator2) creates a vector by copying all elements from the range [iterator1, iterator2).*/
    
    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> left_inorder(inorder.begin(), inorder.begin() + mid);

    vector<int> right_preorder(preorder.begin() + mid + 1, preorder.end()); 
    vector<int> right_inorder(inorder.begin() + mid + 1, inorder.end());

    // Create left and right subtrees recursively
    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);

    return root;
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