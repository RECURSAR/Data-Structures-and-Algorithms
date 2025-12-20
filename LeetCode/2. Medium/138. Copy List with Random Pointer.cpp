#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* createLinkedList(const vector<pair<int, int>>& values);
void printLinkedList(Node* head);

int main()
{
    vector<pair<int, int>> list = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    Node* head = createLinkedList(list);

    cout << "Original list: ";
    printLinkedList(head);

    if(!head){
        cout<<"EMPTY";
        exit(0);
    }

    // Step 1: Create new nodes and interweave them with the original nodes
    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    // Step 2: Assign random pointers to the new nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

    // Step 3: Restore the original list and extract the copied list
    current = head;
    Node* newHead = head->next;
    Node* copyCurrent = newHead;
    while (current) {
        current->next = current->next->next;
        if (copyCurrent->next) {
            copyCurrent->next = copyCurrent->next->next;
        }
        current = current->next;
        copyCurrent = copyCurrent->next;
    }

    cout<<"New List: ";
    printLinkedList(newHead);
   return 0;
}

// Helper function to create a linked list from a vector of pairs
Node* createLinkedList(const vector<pair<int, int>>& values) {
    if (values.empty()) 
        return nullptr;
    
    vector<Node*> nodes;
    for (const auto& val : values) {
        nodes.push_back(new Node(val.first));
    }
    
    for (int i = 0; i < values.size(); ++i) {
        if (i < values.size() - 1) {
            nodes[i]->next = nodes[i + 1];
        }
        if (values[i].second != -1) {
            nodes[i]->random = nodes[values[i].second];
        }
    }
    
    return nodes[0];
}

// Helper function to print the linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << "[" << head->val << ",";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}