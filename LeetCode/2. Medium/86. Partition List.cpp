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
    vector<int> list = {1,4,3,2,5,2};
    int x = 3;
    ListNode* head = createLinkedList(list);
    ListNode* left = new ListNode(), *right = new ListNode();
    ListNode* left_tail = left, *right_tail = right;

    while(head){
        if(head->val < x){
            left_tail->next = head;
            left_tail = left_tail->next;
        }
        else{
            right_tail->next = head;
            right_tail = right_tail->next;
        }

        head = head->next;
    }

    left_tail->next = right->next;
    right_tail->next = NULL;
    printLinkedList(left->next);
    
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