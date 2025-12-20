#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createBinaryTree(const vector<int> &values);
void printBinaryTree(TreeNode *root);

TreeNode* recoverFromPreorder(string traversal, int depth, int& i) {
    int nDashes = 0;
    while (i + nDashes < traversal.length() && traversal[i + nDashes] == '-')
      ++nDashes;
    if (nDashes != depth)
      return nullptr;

    i += depth;
    const int start = i;
    while (i < traversal.length() && isdigit(traversal[i]))
      ++i;

    return new TreeNode(stoi(traversal.substr(start, i - start)), recoverFromPreorder(traversal, depth + 1, i), recoverFromPreorder(traversal, depth + 1, i)); 
}

TreeNode* recoverFromPreorder(string traversal) {
    int i = 0;
    return recoverFromPreorder(traversal, 0, i);
}

int main() {
    string traversal = "1-2--3--4-5--6--7";
    TreeNode* root = recoverFromPreorder(traversal);
    
    printBinaryTree(root);

    return 0;
}

// Helper Function to create a binary tree from a level-order input
TreeNode *createBinaryTree(const vector<int> &values){
    if (values.empty() || values[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper Function to print the binary tree in level order
void printBinaryTree(TreeNode *root){
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current)
        {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
        else
        {
            cout << "null ";
        }
    }

    cout << endl;
}