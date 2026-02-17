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

Node *insertAtPos(Node *head, int p, int x) {
    Node *current = head;
    int currentPosition = 0;
    
    while(current != NULL) {
        if(currentPosition == p) {
            Node* newNode = new Node(x);

            newNode->prev = current;
            newNode->next = current->next;

            if(current->next != NULL)
                current->next->prev = newNode;

            current->next = newNode;
            
            break;
        }

        current = current->next;
        
        currentPosition += 1;
    }

    return head;
}

int main() {
    vector<int> list = {2, 4, 5};

    Node *head = createLinkedList(list);
    int p = 2, x = 6;

    insertAtPos(head, p, x);

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