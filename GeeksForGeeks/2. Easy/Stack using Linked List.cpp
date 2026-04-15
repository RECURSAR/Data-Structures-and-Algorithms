#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

class MyStack {
private:
    Node* stkptr;
    int sz;

public:
    MyStack() {
        sz = 0;
        stkptr = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = stkptr;
        stkptr = newNode;

        sz += 1;
    }

    void pop() {
        if (isEmpty()) 
            return;

        Node* temp = stkptr;
        stkptr = stkptr->next;
        delete temp;

        sz -= 1;
    }

    int peek() {
        if (isEmpty()) 
            return -1;

        return stkptr->data;
    }

    bool isEmpty() {
        return stkptr == NULL;
    }

    int size() {
        return sz;
    }
};

vector<string> processQueries(vector<vector<int>>& queries);

int main() {
    vector<vector<int>> q = {{1, 5}, {1, 3}, {1, 4}, {3}, {2}, {5}, {4}};

    vector<string> out = processQueries(q);
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) cout << ", ";
    }

    return 0;
}

vector<string> processQueries(vector<vector<int>>& queries) {
    MyStack stk;
    vector<string> result;

    for (auto& query : queries) {
        int type = query[0];

        if (type == 1)  
            stk.push(query[1]);
        else if (type == 2)  
            stk.pop();
        else if (type == 3)  
            result.push_back(to_string(stk.peek()));
        else if (type == 4)
            result.push_back(stk.isEmpty() ? "true" : "false");
        else if (type == 5)
            result.push_back(to_string(stk.size()));
    }

    return result;
}