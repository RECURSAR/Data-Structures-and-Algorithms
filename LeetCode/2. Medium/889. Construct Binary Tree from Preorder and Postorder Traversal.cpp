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

TreeNode* build(const vector<int>& pre, int preStart, int preEnd,
    const vector<int>& post, int postStart, int postEnd,
    const unordered_map<int, int>& postToIndex) {
    if (preStart > preEnd)
        return nullptr;

    if (preStart == preEnd)
        return new TreeNode(pre[preStart]);

    const int rootVal = pre[preStart];
    const int leftRootVal = pre[preStart + 1];
    const int leftRootPostIndex = postToIndex.at(leftRootVal);
    const int leftSize = leftRootPostIndex - postStart + 1;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(pre, preStart + 1, preStart + leftSize, post, postStart, leftRootPostIndex, postToIndex);
    root->right = build(pre, preStart + leftSize + 1, preEnd, post, leftRootPostIndex + 1, postEnd - 1, postToIndex);

    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int, int> postToIndex;

    for (int i = 0; i < postorder.size(); ++i)
      postToIndex[postorder[i]] = i;

    return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postToIndex);
}

int main() {
    vector<int> preorder = {1,2,4,5,3,6,7}, postorder = {4,5,2,6,7,3,1};
    TreeNode* root = constructFromPrePost(preorder, postorder);

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