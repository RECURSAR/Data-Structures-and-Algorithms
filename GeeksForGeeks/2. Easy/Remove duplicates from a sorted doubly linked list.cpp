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

Node *removeDuplicates(struct Node *head) {
    Node *current = head, *toDelete = NULL;

    while(current != NULL && current->next != NULL) {
        if(current->data == current->next->data) {
            toDelete = current->next;
            current->next = toDelete->next;

            if(toDelete->next != NULL)
                toDelete->next->prev = current;

            delete toDelete;
        }
        else
            current = current->next;
    }

    return head;
}

int main() {
    vector<int> list = {1, 1, 1, 2, 3, 4};

    Node *head = createLinkedList(list);

    head = removeDuplicates(head);

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