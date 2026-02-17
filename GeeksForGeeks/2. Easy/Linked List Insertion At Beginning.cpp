#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

Node* createLinkedList(const vector<int>& values);
void printLinkedList(Node* head);

Node *insertAtFront(Node *head, int x) {
    Node *newNode = new Node(x);
        
    newNode->next = head;

    return newNode;
}

int main() {
    vector<int> list = {2, 10};

    Node *head = createLinkedList(list);
    int x = 6;
    
    head = insertAtFront(head, x);

    printLinkedList(head);

    return 0;
}

// Helper function to create a linked list from a vector of values
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) 
        return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}