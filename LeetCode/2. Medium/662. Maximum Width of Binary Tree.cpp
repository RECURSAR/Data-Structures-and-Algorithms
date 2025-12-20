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

int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;

        int width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long mmin = q.front().second;    // Making the first id starting from zero
            long long first, last;

            for(int i = 0; i < size; i++){
                long long cur_id = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();

                if(i==0)
                    first = cur_id;

                if(i==size-1)
                    last = cur_id;
                
                if(node->left)
                    q.push({node->left, cur_id * 2 + 1});

                if(node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            width = max(width, static_cast<int>(last - first + 1));
        }

        return width;
}

int main() {
    vector<int> list={1,3,2,5,-1,-1,9,6,-1,7};
    TreeNode* root = createBinaryTree(list);

    cout<<widthOfBinaryTree(root)<<endl;

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