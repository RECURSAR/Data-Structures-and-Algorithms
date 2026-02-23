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

ListNode* getKthNode(ListNode *current, int k) {
    while(current != NULL && k > 0) {
        current = current->next;
        k -= 1;
    }

    return current;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = NULL, *current = NULL, *groupPrev = dummy, *groupNext = NULL, *kthNode = NULL, *temp = NULL;

    while(true) {
        kthNode = getKthNode(groupPrev, k);

        if(kthNode == NULL)
            break;
        
        groupNext = kthNode->next;
        prev = groupNext;
        current = groupPrev->next;

        for(int i = 0; i < k; i++) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        temp = groupPrev->next;
        groupPrev->next = kthNode;
        groupPrev = temp;
    }

    return dummy->next;
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode *head = createLinkedList(list);
    
    head = reverseKGroup(head, k);

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