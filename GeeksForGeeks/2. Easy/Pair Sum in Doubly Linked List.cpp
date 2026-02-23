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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int, int>> result;
    Node *left = head, *right = head;
    int temp = 0;

    while(right->next != NULL)
        right = right->next;

    while(left != right && right->next != left) {
        temp = left->data + right->data;;

        if(temp < target) {
            left = left->next;
        }
        else if(temp > target) {
            right = right->prev;
        }
        else {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
    }

    return result;
}

int main() {
    vector<int> list = {1, 2, 4, 5, 6, 8, 9};
    int target = 7;

    Node *head = createLinkedList(list);

    auto result = findPairsWithGivenSum(head, target);
    
    for(auto p : result)
        cout<<"["<<p.first<<" "<<p.second<<"]"<<" ";

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