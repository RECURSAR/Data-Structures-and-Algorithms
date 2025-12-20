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

ListNode* removeElements(ListNode* head, const vector<int>& nums);

int main()
{
    vector<int> list= {1, 2, 1, 2, 1, 2};
    ListNode *head = createLinkedList(list);
    
    // Elements to delete
    vector<int> nums = {1};

    // Remove elements and print the modified list
    head = removeElements(head, nums);
    
    printLinkedList(head);
    
    return 0;
}

// Helper function to remove elements
ListNode* removeElements(ListNode* head, const vector<int>& nums) {
    // Store elements to be deleted in a set
    unordered_set<int> deletions(nums.begin(), nums.end());
    
    // Use a dummy node to handle deletions at the head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* current = dummy;
    
    while (current->next != nullptr) {
        // If the next node's value is in the deletion set
        if (deletions.find(current->next->val) != deletions.end()) {
            // Skip the node by adjusting the next pointer
            ListNode* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete; // Free the memory of the deleted node
        }
        
        else {
            // Move to the next node if no deletion
            current = current->next;
        }
    }
    
    // Return the updated list, skipping the dummy node
    ListNode* newHead = dummy->next;
    delete dummy; // Free the dummy node memory
    return newHead;
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
