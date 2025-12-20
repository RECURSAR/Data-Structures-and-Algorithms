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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

int main()
{
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    TreeNode *root;

    root = buildTree(inorder, postorder);
    printBinaryTree(root);
    
    return 0;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty())
        return NULL;

    TreeNode* root = new TreeNode(postorder.back());
    postorder.pop_back();

    auto index = find(inorder.begin(), inorder.end(), root->val);
    int mid = distance(inorder.begin(), index);

    // Construct right subtree first since postorder processes right subtree before left subtree

    /*vector<int> nigger(a, b) initializes a vector of size a with the value b.
    vector<int> vec(iterator1, iterator2) creates a vector by copying all elements from the range [iterator1, iterator2).*/
    
    vector<int> right_inorder(inorder.begin() + mid + 1, inorder.end());
    vector<int> right_postorder(postorder.begin() + mid, postorder.end());

    vector<int> left_inorder(inorder.begin(), inorder.begin() + mid);
    vector<int> left_postorder(postorder.begin(), postorder.begin() + mid);

    root->right = buildTree(right_inorder, right_postorder);
    root->left = buildTree(left_inorder, left_postorder);

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