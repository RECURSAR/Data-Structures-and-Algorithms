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

// Basic Approach 
/*
void flatten(TreeNode* root){
    static TreeNode *prev = NULL; // To be used as a global variable

    if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
}*/

// Using Morris Traversal
void flatten(TreeNode *root){
    TreeNode* curr = root;

    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode *prev = curr->left;

            // Rightmost node of left-subtree
            while(prev->right)
                prev = prev->right;
            
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL; // Set the left child to NULL
        }
        
        curr = curr->right;
    }
}

int main()
{
    vector<int> list={1,2,5,3,4,-1,6};
    TreeNode* root = createBinaryTree(list);

    flatten(root);
    printBinaryTree(root);
   
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