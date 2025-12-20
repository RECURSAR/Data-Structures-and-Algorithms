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

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root)
        return "";
    
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        if(current == NULL)
            s.append("#,");
        else
            s.append(to_string(current->val) + ",");

        if(current != NULL){
            q.push(current->left);
            q.push(current->right); 
        }     
    }

    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size() == 0)
        return NULL;
    
    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#")
            node->left == NULL;
        else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#")
            node->right == NULL;
        else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main() {
    vector<int> list = {1,2,3,-1,-1,4,5};
    TreeNode *root = createBinaryTree(list);

    cout<<serialize(root)<<endl;
    printBinaryTree(deserialize(serialize(root)));

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