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

int main(){
    vector<int> list = {1, 2, 3, 4, 5}; 
    int left = 2, right = 4;
    
    ListNode* head = createLinkedList(list);
    ListNode* dummy = new ListNode(0, head); // Made a Dummy node with value 0 pointing to head

    cout << "Original list: ";
    printLinkedList(head);

    ListNode* current  = head;
    ListNode* left_previous = dummy;
    ListNode* previous = NULL;
    ListNode* tmpNext;

    // 1 - Reach left index
    for(int i = left - 1; i > 0; i--){
        left_previous = current;
        current = current->next;
    }

    // Now current = left and left_previous is before current
    // 2 - Reverse from left to right
    for(int i = right - left + 1; i > 0; i--){
        tmpNext = current->next;
        current->next = previous;
        previous = current;
        current = tmpNext;
    }

    // 3 - Update Pointers (Last and First)
    // node before left should point at last node and node at right should point at next of initial left node
    left_previous->next->next = current;
    left_previous->next = previous;

    cout << "Reversed List: ";
    printLinkedList(dummy->next);
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