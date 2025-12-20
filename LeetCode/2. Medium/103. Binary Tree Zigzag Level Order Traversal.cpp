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

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

int main()
{
    vector<int> list = {3,9,20,-1,-1,15,7};
    TreeNode *root = createBinaryTree(list);
    vector<vector<int>> result;

    result = zigzagLevelOrder(root);

    for(const auto& innerVec : result){  
        for (int num : innerVec)    
            cout << num << " ";         
        cout << endl;  
    }

   return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL)
        return result;
    
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    // flag is used for taking directions, true means left to right
    bool flag = true;

    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);

        for(int i = 0; i < size; i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            int index = (flag) ? i :  (size - 1 - i);
            
            row[index] = node->val;

            if(node->left)
                nodesQueue.push(node->left);

            if(node->right)
                nodesQueue.push(node->right);
        }

        flag = !flag;
        result.push_back(row);
    }

    return result;
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