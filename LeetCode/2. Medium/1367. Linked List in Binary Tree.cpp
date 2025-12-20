#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) 
            return false;
        
        // Start from current node or try from left/right child
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    // Helper function to check if linked list matches a downward path starting from current tree node.
    bool dfs(ListNode* head, TreeNode* node) {
        if (!head) 
            return true; // If linked list is fully traversed, return true

        if (!node || head->val != node->val) 
            return false; // If values don't match or node is null, return false

        // Recursively check downward path (either left or right)
        return dfs(head->next, node->left) || dfs(head->next, node->right);
    }
};

// Helper function to print if the result is true or false
void printResult(bool result) {
    if (result) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

// Example Usage
int main() {
    // Creating a sample binary tree:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(6);

    // Creating a sample linked list:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);

    Solution solution;
    bool result = solution.isSubPath(head, root);
    
    printResult(result);

    // Free up allocated memory (this is basic, without smart pointers)
    delete head->next->next;
    delete head->next;
    delete head;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
