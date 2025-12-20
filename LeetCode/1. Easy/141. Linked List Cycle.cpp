#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> values);
void createCycle(ListNode* head, int pos);

int main(){
    vector<int> values = {3, 2, 0, -4};
    int cyclePos = 1; // Cycle starts at index 1 (value 2)
    ListNode* head = createLinkedList(values);
    createCycle(head, cyclePos);

    ListNode* slow = head;
    ListNode* fast = head;

    bool result;

    // Head does not exist
    if(!head){
        result = false;
        cout<<result<<endl;
        exit(0);
    }

    // Floyd' Tortoise and Hare Algorithm O(n) time complexity
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            result = true;
            cout<<result<<endl;
            exit(0);
        }
    }

    result = false;
    cout<<result<<endl;

    return 0;

}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(vector<int> values) {
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

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) 
        return;
    
    ListNode* current = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    
    while (current->next != nullptr) {
        if (index == pos) 
            cycleNode = current;

        current = current->next;
        ++index;
    }
    
    current->next = cycleNode;
}