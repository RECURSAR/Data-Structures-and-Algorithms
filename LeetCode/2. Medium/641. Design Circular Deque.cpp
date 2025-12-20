#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class MyCircularDeque {
private:
    vector<int> deque; // Vector to store the deque elements
    int front;         // Index for the front element
    int rear;          // Index for the rear element
    int size;          // Current number of elements in the deque
    int capacity;      // Maximum capacity of the deque

public:
    MyCircularDeque(int k) {
        deque.resize(k);     // Initialize the deque array with size k
        front = 0;           // Initial front position
        rear = 0;            // Initial rear position
        size = 0;            // Start with 0 elements
        capacity = k;        // Set the maximum capacity to k
    }

    // Inserts an element at the front. Returns true if successful.
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity; // Move front backward in a circular way
        deque[front] = value;                      // Insert the value at the new front
        size++;                                    // Increase the size
        return true;
    }

    // Inserts an element at the rear. Returns true if successful.
    bool insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;                       // Insert the value at the current rear
        rear = (rear + 1) % capacity;              // Move rear forward in a circular way
        size++;                                    // Increase the size
        return true;
    }

    // Deletes an element from the front. Returns true if successful.
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;            // Move front forward in a circular way
        size--;                                    // Decrease the size
        return true;
    }

    // Deletes an element from the rear. Returns true if successful.
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;   // Move rear backward in a circular way
        size--;                                    // Decrease the size
        return true;
    }

    // Returns the front element of the deque. Returns -1 if deque is empty.
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];                       // Return the element at the front index
    }

    // Returns the rear element of the deque. Returns -1 if deque is empty.
    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity]; // Return the element before the rear index
    }

    // Checks if the deque is empty.
    bool isEmpty() {
        return size == 0;                          // The deque is empty if size is 0
    }

    // Checks if the deque is full.
    bool isFull() {
        return size == capacity;                   // The deque is full if size equals capacity
    }
};

int main() {
    MyCircularDeque deque(3); // Initialize the deque with capacity 3

    // Test 1: Insert elements at the front and rear
    cout << "Test 1: Insert elements at front and rear" << endl;
    cout << deque.insertLast(1) << endl;  // Insert 1 at the rear, expected output: true
    cout << deque.insertLast(2) << endl;  // Insert 2 at the rear, expected output: true
    cout << deque.insertFront(3) << endl; // Insert 3 at the front, expected output: true
    cout << deque.insertFront(4) << endl; // Insert 4 at the front, but the deque is full, expected output: false

    // Test 2: Check front and rear values
    cout << "Test 2: Check front and rear values" << endl;
    cout << deque.getRear() << endl;  // Expected output: 2 (current rear value)
    cout << deque.getFront() << endl; // Expected output: 3 (current front value)

    // Test 3: Test isFull and delete operations
    cout << "Test 3: Test isFull and delete operations" << endl;
    cout << deque.isFull() << endl;   // Expected output: true (deque is full)
    cout << deque.deleteLast() << endl; // Expected output: true (delete rear element)
    cout << deque.insertFront(4) << endl; // Expected output: true (insert 4 at front after deletion)

    // Test 4: Check after deletion and insertion
    cout << "Test 4: Check front and rear after deletion and insertion" << endl;
    cout << deque.getFront() << endl; // Expected output: 4 (front should be 4)
    cout << deque.getRear() << endl;  // Expected output: 1 (rear should be 1)

    // Test 5: Check if deque is empty
    cout << "Test 5: Check if deque is empty" << endl;
    cout << deque.isEmpty() << endl;  // Expected output: false (deque is not empty)

    // Test 6: Delete front and rear
    cout << "Test 6: Delete front and rear elements" << endl;
    cout << deque.deleteFront() << endl; // Expected output: true (delete front element)
    cout << deque.deleteLast() << endl;  // Expected output: true (delete rear element)
    cout << deque.deleteFront() << endl; // Expected output: true (delete front element)
    cout << deque.isEmpty() << endl;     // Expected output: true (deque is now empty)
    
    // Test 7: Test boundary case with empty deque
    cout << "Test 7: Test boundary case with empty deque" << endl;
    cout << deque.getFront() << endl; // Expected output: -1 (empty deque)
    cout << deque.getRear() << endl;  // Expected output: -1 (empty deque)
    cout << deque.deleteFront() << endl; // Expected output: false (cannot delete from empty deque)
    cout << deque.deleteLast() << endl;  // Expected output: false (cannot delete from empty deque)
    
    return 0;
}