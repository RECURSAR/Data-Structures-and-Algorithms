#include <iostream>
#include <bits/stdc++.h>

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
    vector<int> list1 = {1, 2, 4}; 
    vector<int> list2 = {1, 3, 4}; 
    
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

    ListNode* DummyHead = new ListNode();
    ListNode* current = DummyHead;

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            current->next = l1;
            l1 = l1->next;
        }

        else{
            current->next = l2;
            l2 = l2->next;
        }
        
        current = current->next;
    }

    if (l1 != NULL) 
        current->next = l1;
    else 
        current->next = l2;

    printLinkedList(DummyHead->next);
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