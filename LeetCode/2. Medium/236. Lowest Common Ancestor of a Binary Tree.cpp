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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root == p || root == q)
        return root;
    
    TreeNode* LST = lowestCommonAncestor(root->left, p, q);
    TreeNode* RST = lowestCommonAncestor(root->right, p, q);

    if(LST != NULL && RST !=NULL)
        return root;
    
    // Return Non-NULL value
    if(LST != NULL && RST == NULL)
        return LST;
    else 
        return RST;
}

int main() {
    vector<int> list = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = createBinaryTree(list);

    // Assuming we want to find LCA of nodes with value 5 and 1
    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    // Find the lowest common ancestor
    TreeNode* LCA = lowestCommonAncestor(root, p, q);
    if (LCA) 
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << LCA->val << endl;
    else
        cout << "LCA not found!" << endl;

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