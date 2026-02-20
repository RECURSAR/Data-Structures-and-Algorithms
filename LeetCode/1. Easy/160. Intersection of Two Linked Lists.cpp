#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(const vector<int>& values);
void printLinkedList(ListNode* head);
pair<ListNode*, ListNode*> createIntersectedLists(const vector<int>& list1, const vector<int>& list2, int skipA, int skipB, int intersectVal);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
        
    ListNode *current1 = headA, *current2 = headB;

    while(current1 != current2) {
        current1 = current1 ? current1->next : headB;
        current2 = current2 ? current2->next : headA; 
    }

    return current1;
}

int main() {
    vector<int> list1 = {4, 1, 8, 4, 5}, list2 = {5, 6, 1, 8, 4, 5};
    int intersectVal = 8, skipA = 2, skipB = 3;

    auto [headA, headB] = createIntersectedLists(list1, list2, skipA, skipB, intersectVal);

    cout<<getIntersectionNode(headA, headB)->val;

    return 0;
}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) 
        return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to build two linked lists that share a common tail
pair<ListNode*, ListNode*> createIntersectedLists( const vector<int>& list1, const vector<int>& list2, int skipA, int skipB, int intersectVal) {
    // Build the shared intersection tail from list1[skipA ... end]
    ListNode* intersectionHead = nullptr;
    if (intersectVal != 0) {
        intersectionHead = new ListNode(list1[skipA]);
        ListNode* cur = intersectionHead;
        for (int i = skipA + 1; i < (int)list1.size(); i++) {
            cur->next = new ListNode(list1[i]);
            cur = cur->next;
        }
    }

    // Build the non-shared prefix of listA (list1[0 ... skipA-1])
    ListNode* headA = nullptr;
    if (skipA > 0) {
        headA = new ListNode(list1[0]);
        ListNode* cur = headA;
        for (int i = 1; i < skipA; i++) {
            cur->next = new ListNode(list1[i]);
            cur = cur->next;
        }
        cur->next = intersectionHead;
    } else {
        headA = intersectionHead;
    }

    // Build the non-shared prefix of listB (list2[0 ... skipB-1])
    ListNode* headB = nullptr;
    if (skipB > 0) {
        headB = new ListNode(list2[0]);
        ListNode* cur = headB;
        for (int i = 1; i < skipB; i++) {
            cur->next = new ListNode(list2[i]);
            cur = cur->next;
        }
        cur->next = intersectionHead;
    } else {
        headB = intersectionHead;
    }

    return {headA, headB};
}