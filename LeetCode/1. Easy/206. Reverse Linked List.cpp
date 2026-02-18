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

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *temp = head, *front;

    while(temp != NULL) {
        front = temp->next;
        temp->next = prev;

        prev = temp;
        temp = front;
    }

    return prev;
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};

    ListNode *head = createLinkedList(list);
    
    head = reverseList(head);

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