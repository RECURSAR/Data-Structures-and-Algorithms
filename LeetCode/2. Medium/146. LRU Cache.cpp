#include<iostream>
#include<map>

using namespace std;

struct ListNode{
    int key, val;
    ListNode* prev, *next;
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {} 
};

class LRUCache {
private:
    int capacity;
    map<int, ListNode*> cache;
    ListNode* left, *right;

    // Detaches a node from its current position in the doubly linked list without deleting it.
    void removeNode(ListNode* node) {
        if (node->prev) 
            node->prev->next = node->next;
        if (node->next) 
            node->next->prev = node->prev;
        if (node == left) 
            left = node->next;
        if (node == right) 
            right = node->prev;
    }

    // Inserts a node at the front (at right) of the doubly linked list, indicating it was recently used.
    void addNodeToFront(ListNode* node) {
        node->next = left;
        node->prev = nullptr;
        if (left) 
            left->prev = node;
        left = node;
        if (!right) 
            right = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), left(nullptr), right(nullptr){}

    int get(int key){
        // If key is found, create a new node which is being pointed by cache, and then add that node to the right
        if(cache.find(key) != cache.end()){
            ListNode* node = cache[key];
            removeNode(node);
            addNodeToFront(node);
            return node->val;
        }
        else
            return -1;
    }

    void put(int key, int value){
        // If key is found, update the key-value pair by the current value and then create a new node and add that node to the right
        if(cache.find(key) != cache.end()){
            ListNode* node = cache[key];
            node->val = value;
            removeNode(node);
            addNodeToFront(node);   
        }
        else{
            // If number of keys exceed the capcity then delete the LRU 
            if(cache.size() == capacity){
                ListNode* toDelete = right;
                cache.erase(right->key);
                removeNode(right);
                right = toDelete->prev; // Update right pointer before deletion
                delete toDelete;
            }

            ListNode* newNode = new ListNode(key, value);
            addNodeToFront(newNode);
            cache[key] = newNode;
        }
    }
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); 
    lRUCache.put(2, 2); 
    cout << lRUCache.get(1) << endl;   
    lRUCache.put(3, 3); 
    cout << lRUCache.get(2) << endl;    
    lRUCache.put(4, 4); 
    cout << lRUCache.get(1) << endl;    
    cout << lRUCache.get(3) << endl;    
    cout << lRUCache.get(4) << endl;    
    return 0;
}