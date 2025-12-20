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

int minimumOperations(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> q{{root}};

    // e.g. vals = [7, 6, 8, 5]
    // [2, 1, 3, 0]: Initialize the ids based on the order of vals.
    // [3, 1, 2, 0]: Swap 2 with 3, so 2 is in the right place (i == ids[i]).
    // [0, 1, 2, 3]: Swap 3 with 0, so 3 is in the right place.
    while (!q.empty()) {
      vector<int> vals;
      vector<int> ids(q.size());

      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        vals.push_back(node->val);

        if (node->left != nullptr)
          q.push(node->left);

        if (node->right != nullptr)
          q.push(node->right);
      }

      iota(ids.begin(), ids.end(), 0);
      sort(ids.begin(), ids.end(), [&vals](int i, int j) { return vals[i] < vals[j]; });
      
      for (int i = 0; i < ids.size(); ++i)
        for (; ids[i] != i; ++ans)
          swap(ids[i], ids[ids[i]]);
    }

    return ans;
}

int main() {
    vector<int> list = {1,4,3,7,6,8,5,-1,-1,-1,-1,9,-1,10};
    TreeNode* root = createBinaryTree(list);
    
    cout<<minimumOperations(root);

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