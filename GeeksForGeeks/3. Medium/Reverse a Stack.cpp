#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> buildStack(const vector<int> &values);
void printStack(stack<int> st);

void insertInReverse(stack<int> &st, int temp) {
    if(st.empty()) {
        st.push(temp);
        return;
    }
    
    int val = st.top();
    st.pop();
    
    insertInReverse(st, temp);
    
    st.push(val);
}

void reverseStack(stack<int> &st) {
    if(!st.empty()) {
        int temp = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertInReverse(st, temp);
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4};
    stack<int> st = buildStack(values);

    reverseStack(st);

    printStack(st);

    return 0;
}

// Helper Function to initialize a stack
stack<int> buildStack(const vector<int> &values) {
    stack<int> st;
    for (int value : values) {
        st.push(value);
    }
    return st;
}

// Helper Function to print stack values (top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}