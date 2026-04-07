#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class myStack {
    private:
        int capacity, stkptr, *stack;

    public:
        myStack(int n) {
            capacity = n;
            stack = new int[capacity];
            stkptr = 0;
        }

        bool isEmpty() {
            return stkptr == 0;
        }

        bool isFull() {
            return stkptr == capacity;
        }

        void push(int x) {
            if(isFull())
                return;

            stack[stkptr] = x;
            stkptr += 1;
        }

        void pop() {
            if(isEmpty())
                return;
            
            stkptr -= 1;
        }

        int peek() {
            if(isEmpty())
                return -1;
            
            return stack[stkptr - 1];
        }
};

vector<string> processQueries(int n, vector<vector<int>> &queries);

int main() {
    int n = 3;
    vector<vector<int>> queries = {{1, 5}, {1, 3}, {3}, {2}, {4}, {5}};

    vector<string> output = processQueries(n, queries);
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }

    return 0;
}

// Helper function to process queries
vector<string> processQueries(int n, vector<vector<int>> &queries) {
    myStack st(n);
    vector<string> result;

    for (auto &q : queries) {
        int type = q[0];

        if (type == 1)
            st.push(q[1]); 
        else if (type == 2)
            st.pop(); 
        else if (type == 3)
            result.push_back(to_string(st.peek())); 
        else if (type == 4)
            result.push_back(st.isEmpty() ? "true" : "false"); 
        else if (type == 5)
            result.push_back(st.isFull() ? "true" : "false");
    }

    return result;
}