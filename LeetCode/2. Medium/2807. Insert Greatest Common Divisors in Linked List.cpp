#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(const vector<int>& values);
void printLinkedList(ListNode* head);

int gcd(int a, int b) {
    // If b becomes 0 then GCD is a
    if (b == 0)
        return a;

    return gcd(b, a % b); // Added missing semicolon
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode *current = head, *next = head->next;

    if (!head->next)
        return head;

    while (next != NULL) {
        int GCD = gcd(current->val, next->val);
        ListNode *newNode = new ListNode(GCD, next); // Changed variable name from 'new' to 'newNode'
        current->next = newNode;
        current = next;
        next = next->next;
    }

    return head;
}

int main() {
    vector<int> list = {18, 6, 10, 3};
    ListNode *head = createLinkedList(list);

    ListNode *result = insertGreatestCommonDivisors(head);
    printLinkedList(result);

    return 0;
}

// Dummy implementations for createLinkedList and printLinkedList
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}