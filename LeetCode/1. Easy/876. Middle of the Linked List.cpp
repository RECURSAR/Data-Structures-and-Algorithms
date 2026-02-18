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

// Brute-Force Approach
/*
ListNode* middleNode(ListNode* head) {
    ListNode *current = head;
    int length = 0;

    while(current != NULL) {
        length += 1;
        current = current->next;
    }

    current = head;
    for(int i = 0; i < length / 2; i++)
        current = current->next;

    return current;   
}
*/

// Optimal Approach using Fast and Slow Pointers
ListNode* middleNode(ListNode* head) {
    ListNode *fast = head, *slow = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};

    ListNode *head = createLinkedList(list);
    ListNode *middle = middleNode(head);

    printLinkedList(middle);

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