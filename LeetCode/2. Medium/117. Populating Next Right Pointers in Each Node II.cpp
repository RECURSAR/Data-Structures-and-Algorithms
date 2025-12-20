#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node* createBinaryTree(const vector<int>& values);
void printTreeByNext(Node* root);
Node* connect(Node* root);

int main() {
    vector<int> values = {1, 2, 3, 4, 5, -1, 7};
    Node* root = createBinaryTree(values);

    Node* res = connect(root);

    cout << "Tree after connecting next pointers: ";
    printTreeByNext(res);

    return 0;
}

Node* connect(Node* root) {
    if (!root) 
        return NULL;

    Node* levelStart = root;            // Start of the current level.

    while (levelStart) {
        Node* cur = levelStart;         // Current node in the current level.
        Node* nextLevelStart = NULL;    // Start of the next level.
        Node* prev = NULL;              // Previous node in the next level.

        while (cur) {
            if (cur->left) {
                if (prev) {
                    prev->next = cur->left;
                } else {
                    nextLevelStart = cur->left;
                }
                prev = cur->left;
            }
            if (cur->right) {
                if (prev) {
                    prev->next = cur->right;
                } else {
                    nextLevelStart = cur->right;
                }
                prev = cur->right;
            }
            
            // Move to the next node in the current level.
            cur = cur->next; 
        }

        // Move to the next level.
        levelStart = nextLevelStart;
    }

    return root;
}

// Helper function to create a binary tree from a vector of values
Node* createBinaryTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return NULL;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        Node* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new Node(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            current->right = new Node(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to print the tree levels using the next pointers
void printTreeByNext(Node* root) {
    Node* level_start = root;
    while (level_start) {
        Node* current = level_start;
        level_start = NULL;
        while (current) {
            cout << current->val << " ";
            if (!level_start) {
                if (current->left) {
                    level_start = current->left;
                } else if (current->right) {
                    level_start = current->right;
                }
            }
            current = current->next;
        }
        cout << "# "; // End of level
    }
    cout << endl;
}