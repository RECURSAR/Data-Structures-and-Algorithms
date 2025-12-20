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

vector<vector<int>> verticalTraversal(TreeNode* root);

int main()
{
    vector<int> list = {1,2,3,4,5,6,7};
    TreeNode *root = createBinaryTree(list);
    vector<vector<int>> result;

    result = verticalTraversal(root);

    for(const auto& innerVec : result){  
        for (int num : innerVec)    
            cout << num << " ";         
        cout << endl;  
    }

    return 0;
}

vector<vector<int>> verticalTraversal(TreeNode* root){
    // A multiset is taken because a level can have nodes with same value as set will only take unique value
    // vertical, level, multiple-nodes
    map<int, map<int, multiset<int>>> nodes;
    // node, vertical, level
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0,0}});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);

        // Left child means (x) vertical - 1, (y) level will always be incremented
        if(node->left)
            todo.push({node->left, {x - 1, y + 1}});
            
        // Right child means (x) vertical + 1, (y) level will always be incremented
        if(node->right)
            todo.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second)
            col.insert(col.end(), q.second.begin(), q.second.end());

        ans.push_back(col);
    }
    
    return ans;
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