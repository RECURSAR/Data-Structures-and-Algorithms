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

bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head, 
             *prev = NULL, *next = NULL, 
             *first = NULL, *second = NULL;

    // Slow end up at mid point and Fast ends up at the last point
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversing the second half after slow
    while(slow != NULL) {
        next = slow->next;
        slow->next = prev;

        prev = slow;
        slow = next;
    }

    // Iterating both halves simulataneously, original first half and reversed second half
    first = head;
    second = prev;

    while(second != NULL) {
        if(first->val != second->val)
            return false;
        
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    vector<int> list = {1, 2, 2, 1};

    ListNode *head = createLinkedList(list);
    
    isPalindrome(head) ? cout<<"True" : cout<<"False";

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