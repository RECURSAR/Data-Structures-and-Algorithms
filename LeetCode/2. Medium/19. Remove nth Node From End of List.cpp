#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(const vector<int>& values);
void printLinkedList(ListNode* head);

int main()
{
    vector<int> list = {1, 2, 3, 4, 5};
    int n = 2;
    
    ListNode* head = createLinkedList(list);
    ListNode *dummy_head = new ListNode(0, head);
    ListNode *left = dummy_head, *right;

    right = head;

    while (n > 0 && right) {
        right = right->next;
        n--;
    }

    while (right) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;
    printLinkedList(head);

   return 0;
}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) 
        return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
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