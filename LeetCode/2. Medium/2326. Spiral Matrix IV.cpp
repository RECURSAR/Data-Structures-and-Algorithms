#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printMatrix(const vector<vector<int>>& matrix);
ListNode* createLinkedList(const vector<int>& values);

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    // Initialize the matrix with -1
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    
    // Boundaries for the spiral traversal
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    // Pointer to traverse the linked list
    ListNode* current = head;

    // Fill the matrix in a spiral order
    while (top <= bottom && left <= right && current != nullptr) {
        // Traverse from left to right
        for (int i = left; i <= right && current != nullptr; ++i) {
            matrix[top][i] = current->val;
            current = current->next;
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom && current != nullptr; ++i) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        right--;

        // Traverse from right to left
        for (int i = right; i >= left && current != nullptr; --i) {
            matrix[bottom][i] = current->val;
            current = current->next;
        }
        bottom--;

        // Traverse from bottom to top
        for (int i = bottom; i >= top && current != nullptr; --i) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        left++;
    }

    return matrix;
}

int main() {
    int m = 3, n = 3;
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = createLinkedList(values);

    // Generate the matrix
    vector<vector<int>> matrix = spiralMatrix(m, n, head);

    // Print the matrix
    printMatrix(matrix);

    return 0;
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}