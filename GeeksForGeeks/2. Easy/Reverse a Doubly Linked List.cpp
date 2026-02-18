#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

Node* createLinkedList(const vector<int>& values);
void printLinkedList(Node* head);

Node *reverse(Node *head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *prev = NULL, *current = head;

    while(current != NULL) {
        prev = current->prev;

        current->prev = current->next;
        current->next = prev;

        current = current->prev;
    }

    return prev->prev;
}

int main() {
    vector<int> list = {1, 2};

    Node *head = createLinkedList(list);

    head = reverse(head);

    printLinkedList(head);

    return 0;
}

// Helper function to create a doubly linked list from a vector of values
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) 
        return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current->next->prev = current;  // Link previous pointer
        current = current->next;
    }
    return head;
}

// Helper function to print a doubly linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}