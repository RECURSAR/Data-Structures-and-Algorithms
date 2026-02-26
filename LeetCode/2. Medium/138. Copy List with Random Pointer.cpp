#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* createLinkedList(const vector<int>& values);
void printLinkedList(Node* head);
void setRandomPointers(Node* head, const vector<int>& randomIndices);

void insertCopyInBetween(Node *head) {
    Node *current = head, *next = NULL;

    while(current != NULL) {
        next = current->next;
        Node *copy = new Node(current->val);
        
        copy->next = next;
        current->next = copy;

        current = next;
    }
}

void connectRandomPointers(Node *head) {
    Node *current = head;

    while(current != NULL) {
        Node *copy = current->next;

        if(current->random != NULL)
            copy->random = current->random->next;   // Pointing to the copy that is why it is next
        else
            copy->random = NULL;
        
        current = current->next->next;
    }
}

Node* getDeepCopyList(Node *head) {
    Node *dummy = new Node(0);
    Node *result = dummy;
    Node *current = head;

    while(current != NULL) {
        result->next = current->next;
        result = result->next;

        current->next = current->next->next;
        current = current->next;
    }

    return dummy->next;
}

Node* copyRandomList(Node* head) {
    if(head == NULL)
        return head;

    // 1. Inserting copy of nodes in between
    insertCopyInBetween(head);
    
    // 2. Connect random pointers of copied nodes
    connectRandomPointers(head);

    // 3. Get the final deep copy of the linked list
    return getDeepCopyList(head);
}

int main() {
    vector<int> values = {7, 13, 11, 10, 1}, randomIndices = {-1, 0, 4, 2, 0};

    Node* head = createLinkedList(values);
    setRandomPointers(head, randomIndices);

    Node* copied = copyRandomList(head);

    printLinkedList(copied);

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

// Helper function to print a linked list with random pointer values
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << "[" << head->val << ", ";
        if (head->random != nullptr)
            cout << head->random->val;
        else
            cout << "null";
        cout << "]";
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to set random pointers by index (-1 means nullptr)
void setRandomPointers(Node* head, const vector<int>& randomIndices) {
    vector<Node*> nodes;
    Node* current = head;
    while (current != nullptr) {
        nodes.push_back(current);
        current = current->next;
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        int idx = randomIndices[i];
        nodes[i]->random = (idx == -1) ? nullptr : nodes[idx];
    }
}