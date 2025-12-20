#include <iostream>
#include <bits/stdc++.h>

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

class FindElements {
public:
    FindElements(TreeNode *root)
    {
        dfs(root, 0);
    }

    bool find(int target)
    {
        return vals.find(target) != vals.end();
    }

private:
    unordered_set<int> vals;

    void dfs(TreeNode *root, int val)
    {
        if (root == nullptr)
            return;

        root->val = val;
        vals.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
};

int main() {
    TreeNode* root = new TreeNode(-1);
    root->right = new TreeNode(-1);
    
    FindElements* obj = new FindElements(root);
    
    cout << boolalpha;  // print bool values as true/false
    cout << "find(1): " << obj->find(1) << endl; // Expected output: false
    cout << "find(2): " << obj->find(2) << endl; // Expected output: true

    delete obj;
    delete root->right;
    delete root;

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