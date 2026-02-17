#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(const vector<int>& values);
void printLinkedList(ListNode* head);

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    vector<int> list = {4, 5, 1, 9};

    ListNode *head = createLinkedList(list);
    ListNode *removeNode = head;
    int node = 5;

    while(removeNode->val != node)
        removeNode = removeNode->next;

    deleteNode(removeNode);

    printLinkedList(head);

    return 0;
}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) 
        return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}