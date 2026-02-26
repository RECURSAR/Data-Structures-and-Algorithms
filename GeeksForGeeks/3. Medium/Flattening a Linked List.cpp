#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* bottom;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
        bottom = NULL;
    }

    // Parameterised Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->bottom = NULL;
    }
};

Node* createLinkedList(const vector<vector<int>>& values);
void printLinkedList(Node* head);

Node* merge(Node* list1, Node* list2) {
    Node* dummyNode = new Node(0);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else {
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }

        res->next = NULL;
    }

    // Connect the remaining elements if any
    if(list1)
        res->bottom = list1;
    else
        res->bottom = list2;

    // Break the last node's link to prevent cycles
    if(dummyNode->bottom != NULL)
        dummyNode->bottom->next = NULL;
    
    return dummyNode->bottom;
}

Node* flatten(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    // Recursively flatten the rest of the linked list
    Node* mergedHead = flatten(head->next);
    
    head = merge(head, mergedHead);

    return head;
}

int main() {
    vector<vector<int>> list = {{5, 7, 8}, {10, 20}, {19, 22}, {28, 40, 45}};

    Node *head = createLinkedList(list);
    
    head = flatten(head);

    printLinkedList(head);

    return 0;
}

// Helper function to create a multi-level linked list from a vector of vectors.
Node* createLinkedList(const vector<vector<int>>& values) {
    if (values.empty())
        return nullptr;

    Node* head = nullptr;
    Node* currentNext = nullptr;

    for (const auto& chain : values) {
        if (chain.empty()) continue;

        Node* chainHead = new Node(chain[0]);

        if (!head) {
            head = chainHead;
            currentNext = chainHead;
        } else {
            currentNext->next = chainHead;
            currentNext = chainHead;
        }

        Node* currentBottom = chainHead;
        for (size_t i = 1; i < chain.size(); ++i) {
            currentBottom->bottom = new Node(chain[i]);
            currentBottom = currentBottom->bottom;
        }
    }

    return head;
}

// Helper function to print the flattened linked list using the bottom pointer.
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->bottom != nullptr) cout << " -> ";
        head = head->bottom;
    }
    cout << endl;
}