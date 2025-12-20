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

void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode *target){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
            
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }        
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty()){
        int size = q.size();

        if(curr_level++ == k)
            break;

        for(int i = 0; i < size; i++){
            TreeNode *current = q.front();
            q.pop();
            
            // If left node exists and is not visited
            if(current->left && visited[current->left] == false){
                q.push(current->left);
                visited[current->left] = true;
            }

            // If right node exists and is not visited
            if(current->right && visited[current->right] == false){
                q.push(current->right);
                visited[current->right] = true;
            }

            // If parent node exists and is not visited
            if(parent_track[current] && visited[parent_track[current]] == false){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        result.push_back(current->val);
    }

    return result;
}

int main() {
    vector<int> list={3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = createBinaryTree(list);
    int k = 2;
    TreeNode *target = root->left;

    vector<int> Knodes = distanceK(root, target, k);
    for(auto it: Knodes)
        cout<<it;

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