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

// Helper Function to calculate the height of the tree rooted at `root`.
int height(TreeNode* root, unordered_map<int, int>& valToHeight) {
    if (root == nullptr)
        return 0;

    auto it = valToHeight.find(root->val);
    if (it != valToHeight.cend())
        return it->second;

    return valToHeight[root->val] = (1 + max(height(root->left, valToHeight), height(root->right, valToHeight)));
}

// Helper DFS Function
void dfs(TreeNode* root, int depth, int maxHeight,
         unordered_map<int, int>& valToMaxHeight, unordered_map<int, int>& valToHeight) {
    if (root == nullptr)
        return;

    valToMaxHeight[root->val] = maxHeight;

    dfs(root->left, depth + 1, max(maxHeight, depth + height(root->right, valToHeight)), valToMaxHeight, valToHeight);
    dfs(root->right, depth + 1, max(maxHeight, depth + height(root->left, valToHeight)), valToMaxHeight, valToHeight);
}

// Main treeQueries function
vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> ans;
    unordered_map<int, int> valToMaxHeight;
    unordered_map<int, int> valToHeight;

    height(root, valToHeight);
    dfs(root, 0, 0, valToMaxHeight, valToHeight);

    for (const int query : queries)
        ans.push_back(valToMaxHeight[query]);

    return ans;
}

int main() {
    vector<int> list = {5,8,9,2,1,3,7,4,6}, queries = {3,2,4,8};
    TreeNode *root = createBinaryTree(list);

    vector<int> result = treeQueries(root, queries);
    for (auto it : result)
        cout << it << " ";

    return 0;
}

// Helper Function to create a binary tree from a level-order input
TreeNode* createBinaryTree(const vector<int>& values) {
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
void printBinaryTree(TreeNode* root) {
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