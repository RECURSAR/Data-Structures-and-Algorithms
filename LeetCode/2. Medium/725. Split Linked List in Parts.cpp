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

vector<ListNode*> splitListToParts(ListNode* head, int k){
    vector<ListNode*> result(k, NULL);  // Initialize result with k nulls
    
    // Step 1: Calculate the total length of the list
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    
    // Step 2: Determine the size of each part
    int base_size = length / k;  // Minimum size of each part
    int extra_nodes = length % k; // Parts that get an extra node

    current = head;
    for (int i = 0; i < k; ++i) {
        if (!current) 
            break;  // If we've reached the end of the list
        
        result[i] = current;  // Start of the current part
        int part_size = base_size + (extra_nodes > 0 ? 1 : 0);  // Size of current part
        extra_nodes--;  // Decrease extra node count
        
        // Step 3: Move to the end of the current part
        for (int j = 1; j < part_size; ++j) {
            current = current->next;
        }
        
        // Break the link to the rest of the list and move to the next part
        ListNode* next_part = current->next;
        current->next = nullptr;
        current = next_part;
    }
    
    return result;
}

int main()
{
    vector<int> list= {1, 2, 3};
    ListNode *head = createLinkedList(list);
    int k = 5;

    vector<ListNode*> res = splitListToParts(head, k);

    for (int i = 0; i < k; ++i) {
        cout << "Part " << i + 1 << ": ";
        printLinkedList(res[i]);
    }
    
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
