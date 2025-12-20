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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    // Base Cases
    if(!root1 && !root2)    // Both lists are empty
        return true;
    if(!root1 || !root2)    // One of the lists is empty
        return false;
    if(root1->val != root2->val)   // Root values don't match
        return false;
    
    bool withoutFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    bool withFlip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

    return withoutFlip || withFlip;    
}

int main()
{
    vector<int> list1 = {1,2,3,4,5,6,-1,-1,-1,7,8}, list2 = {1,3,2,-1,6,4,5,-1,-1,-1,-1,8,7};
    TreeNode *root1 = createBinaryTree(list1), *root2 = createBinaryTree(list2);

    cout<<flipEquiv(root1, root2);

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