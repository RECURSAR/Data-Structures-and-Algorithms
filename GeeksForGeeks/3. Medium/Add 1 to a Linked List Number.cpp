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

int addOneUntil(Node *current) {
    if(current == NULL)
        return 1;

    int carry = addOneUntil(current->next);
    int sum = current->data + carry;

    current->data = sum % 10;

    return sum / 10;
}

Node* addOne(Node* head) {
    Node *newHead = NULL;
    int carry = addOneUntil(head);

    if(carry != 0) {
        newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }

    return head;
}

int main() {
    vector<int> list = {4, 5, 6};

    Node *head = createLinkedList(list);
    
    head = addOne(head);

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