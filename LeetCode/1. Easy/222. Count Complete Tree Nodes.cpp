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
int countNodes(TreeNode* root);

int main()
{
    vector<int> list = {1,2,3,4,5,6};
    TreeNode *root = createBinaryTree(list);
    int total_nodes = 0;

    total_nodes = countNodes(root);
    cout<<total_nodes;

   return 0;
}

int countNodes(TreeNode* root){
    if(root==NULL)
        return 0;
    
    int left_level = 1;
    int right_level = 1;
    TreeNode *Left = root->left;
    TreeNode *Right = root->right;

    // Traversing the leftmost branch of the tree
    while(1){
        if(Left==NULL)
            break;
        Left = Left->left;
        left_level++;
    }

    // Traversing the rightmost branch of the tree
    while(1){
        if(Right==NULL)
            break;
        Right = Right->right;
        right_level++;
    }

    // Checking if the tree is a perfect binary tree
    if(left_level == right_level)
        return pow(2,left_level)-1;
    
    // Counting nodes for non-perfect binary trees
    return 1 + countNodes(root->left) + countNodes(root->right);
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