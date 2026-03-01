#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> buildStack(const vector<int> &values);
void printStack(stack<int> st);

void insertInSorted(stack<int> &st, int temp) {
    if(st.empty() || st.top() <= temp) {
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();
    insertInSorted(st, temp);

    st.push(val);
}

void sortStack(stack<int> &st) {
    if(!st.empty()) {
        int temp = st.top();
        st.pop();

        sortStack(st);

        insertInSorted(st, temp);
    }
}

int main() {
    vector<int> values = {1, 2, 3};
    stack<int> st = buildStack(values);

    sortStack(st);

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