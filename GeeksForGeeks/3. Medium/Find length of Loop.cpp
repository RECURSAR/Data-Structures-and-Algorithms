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
Node* createLinkedListWithCycle(const vector<int>& values, int pos);

int lengthOfLoop(Node *head) {
    Node *slow = head, *fast = head;
    int length = 0;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            length = 1;
            fast = fast->next;

            while(fast != slow) {
                length += 1;
                fast = fast->next;
            }

            return length;
        }
    }

    return length;
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};
    int pos = 2;

    Node *head = createLinkedListWithCycle(list, pos);
    
    cout<<lengthOfLoop(head);

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

// Helper function to create a linked list with a cycle
Node* createLinkedListWithCycle(const vector<int>& values, int pos) {
    if (values.empty()) 
        return nullptr;
    
    Node* head = new Node(values[0]);
    Node* current = head;
    Node* cycleNode = nullptr;
    
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
        
        // Track the node at position pos
        if ((int)i == pos) {
            cycleNode = current;
        }
    }
    
    // Connect tail to the node at position pos to create a cycle
    if (cycleNode != nullptr) {
        current->next = cycleNode;
    }
    
    return head;
}