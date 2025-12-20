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
    vector<int> list = {1,2,3,3,4,4,5};
    ListNode* head = createLinkedList(list);
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy, *temp;

    while(current->next != NULL){
        // If next two nodes are duplicate then move the current->next forward
        if((current->next && current->next->next) && current->next->val == current->next->next->val){
            temp = current->next->next;
            while((temp && temp->next) && temp->val == temp->next->val)
                temp = temp->next;
            
            current->next = temp->next;
        }
        // If next two nodes are not duplicate move current to current->next
        else
            current = current->next;
    }

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