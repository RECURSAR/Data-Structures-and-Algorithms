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

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
            return head;
        
    ListNode *current = head, *newHead = NULL, *newTail = NULL;
    int length = 1, stepsToTail = 0;

    while(current->next != NULL) {
        current = current->next;
        length += 1;
    }

    current->next = head;

    k = k % length;
    stepsToTail = length - k;
    newTail = head;

    for(int i = 1; i < stepsToTail; i++)
        newTail = newTail->next;

    newHead = newTail->next;
    newTail->next = NULL;
    
    return newHead;
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode *head = createLinkedList(list);
    
    head = rotateRight(head, k);

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