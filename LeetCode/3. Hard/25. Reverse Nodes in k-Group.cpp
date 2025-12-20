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
ListNode* getkth(ListNode*, int);

int main()
{
    vector<int> list = {1,2,3,4,5};
    int k = 2;
    ListNode* head = createLinkedList(list);
    
    ListNode* dummy = new ListNode(0, head);
    ListNode* groupPrev = dummy, *kth, *groupNext, *prev, *curr, *temp;

    while(1){
        kth = getkth(groupPrev, k);
        if(kth == NULL)
            break;
        groupNext = kth->next;

        // Reversing the group
        prev = kth->next;
        curr = groupPrev->next;

        while(curr != groupNext){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    printLinkedList(dummy->next);

    return 0;
}

// Helper function to calculate how long is a single group which needs to be reversed
ListNode* getkth(ListNode* curr, int k){
    while(curr && k > 0){
        curr = curr->next;
        k--;
    }
    return curr;
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