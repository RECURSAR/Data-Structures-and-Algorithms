#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class CustomStack {
private:
    vector<int> stack;
    vector<int> increments;  // Renamed from 'inc' to 'increments' to avoid conflicts
    int maxSize;
    
public:
    // Constructor to initialize the stack with maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        // We only need to ensure the stack size never exceeds maxSize
        stack.reserve(maxSize);    // Pre-allocate space for the stack
        increments.resize(maxSize, 0);  // Initialize the increments array to all 0's
    }
    
    // Pushes an element onto the stack if it is not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            increments[stack.size() - 1] = 0;  // Initialize increment value for this element
        }
    }
    
    // Pops the top element and applies any lazy increment
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        
        int i = stack.size() - 1;  // Index of the top element
        int res = stack[i] + increments[i];  // Apply the increment to the top element
        
        // If there is an increment for this element, pass it to the next element
        if (i > 0) {
            increments[i - 1] += increments[i];  // Pass increment to the next element (below top)
        }
        
        // Remove the top element and its associated increment value
        stack.pop_back();
        increments.pop_back();
        
        return res;
    }
    
    // Increments the bottom k elements of the stack by val
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        if (limit > 0) {
            increments[limit - 1] += val;  // Apply the increment lazily to the k-th element
        }
    }
};

int main() {
    CustomStack* obj = new CustomStack(5); // Create a stack with max size of 5
    obj->push(1);                          // Stack: [1]
    obj->push(2);                          // Stack: [1, 2]
    obj->push(3);                          // Stack: [1, 2, 3]
    
    cout << obj->pop() << endl;            // Pops 3, returns 3
    obj->increment(2, 100);                      // Increment bottom 2 elements by 100, Stack: [101, 102]
    
    obj->push(4);                          // Stack: [101, 102, 4]
    cout << obj->pop() << endl;            // Pops 4, returns 4
    cout << obj->pop() << endl;            // Pops 102, returns 102
    cout << obj->pop() << endl;            // Pops 101, returns 101
    
    return 0;
}
