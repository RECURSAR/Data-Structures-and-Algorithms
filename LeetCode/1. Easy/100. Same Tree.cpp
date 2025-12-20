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
bool isSameTree(TreeNode*, TreeNode*);

int main()
{
    vector<int> tree1 = {1,2,3}, tree2 = {1,2,3};
    TreeNode *p = createBinaryTree(tree1), *q = createBinaryTree(tree2);
    bool result;

    result = isSameTree(p,q);
    cout<<result<<endl;
   return 0;
}

bool isSameTree(TreeNode *p, TreeNode *q){
    if(p == NULL && q == NULL)
        return true;

    // Either one of the node is not NULL
    if(p == NULL || q == NULL)
        return false;

    if(p->val != q-> val)
        return false;
    
    // If both trees are same then their will return statement will be like return True && True which gives out true otherwise
    // in any other case the ouput will be false
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

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