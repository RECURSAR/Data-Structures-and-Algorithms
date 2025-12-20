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
    vector<int> list = {1,2,3,4,5};
    int k = 2, i = 0, len = 1;
    ListNode* head = createLinkedList(list);
    ListNode* last = head, *current, *newHead;

    if(head == NULL){
        cout<<"Nothing in head"<<endl;
        exit(0);
    }

    while(last->next){
        last = last->next;
        len++;
    }

    // If k is a multiple of len then the entire linked list will be rotated and remain the same as original
    k = k % len;
    if(k == 0){
        printLinkedList(head);
        exit(0);
    }

    // Reaching the node from where we will remove and add remaining list to front
    current = head;
    for(i = 0; i < len - k - 1; i++)
        current = current->next;
    

    newHead = current->next;
    current->next = NULL;
    last->next = head;
  
    printLinkedList(newHead);
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