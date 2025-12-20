#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(const vector<int>& values);
void printLinkedList(ListNode* head);

int main(){

    vector<int> list1 = {2, 4, 3}; // Represents number 342
    vector<int> list2 = {5, 6, 4}; // Represents number 465
    
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;
    int carry = 0, d1, d2;

    // we are taking carry in while loop because of an edge case i.e 7 + 7 = 14, only one node is present
    // in both the linked list but carry exists
    while(l1 != NULL || l2 != NULL || carry != 0){
        d1 = (l1 != NULL) ? l1->val : 0;
        d2 = (l2 != NULL) ? l2->val : 0;

        int sum = d1 + d2 + carry;
        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;

        if(l1 != NULL)
            l1 = l1->next;
        
        if(l2 != NULL)
            l2 = l2->next;
    }

    printLinkedList(dummyHead->next);

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
