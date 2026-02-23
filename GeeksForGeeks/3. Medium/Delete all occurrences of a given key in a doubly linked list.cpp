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

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    Node *current = *head_ref, *toDelete = NULL;

    while (current != NULL) {
        if(current->data == x) {
            if(current->prev != NULL)
                current->prev->next = current->next;
            else
                *head_ref = current->next;

            if(current->next != NULL)
                current->next->prev = current->prev;

            toDelete = current;
            current = current->next;
            delete toDelete;
        }
        else
            current = current->next;
    }
}

int main() {
    vector<int> list = {2, 2, 10, 8, 4, 2, 5, 2};
    int x = 2;

    Node *head = createLinkedList(list);
    Node **head_ref = &head;

    deleteAllOccurOfX(head_ref, x);

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