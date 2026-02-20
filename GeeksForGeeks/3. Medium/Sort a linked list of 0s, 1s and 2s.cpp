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

Node* segregate(Node* head) {
    Node *zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
    Node *zeroTail = zero, *oneTail = one, *twoTail = two;
    
    Node *current = head;

    while(current != NULL) {
        if(current->data == 0) {
            zeroTail->next = current;
            zeroTail = zeroTail->next;
        }
        else if(current->data == 1) {
            oneTail->next = current;
            oneTail = oneTail->next;
        }
        else {
            twoTail->next = current;
            twoTail = twoTail->next;
        }

        current = current->next;
    }

    zeroTail->next = one->next ? one->next : two->next;
    oneTail->next = two->next;
    twoTail->next = NULL;

    head = zero->next;

    delete zero;
    delete one;
    delete two;
    
    return head;
}

int main() {
    vector<int> list = {1, 2, 2, 1, 2, 0, 2, 2};

    Node *head = createLinkedList(list);
    
    head = segregate(head);

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