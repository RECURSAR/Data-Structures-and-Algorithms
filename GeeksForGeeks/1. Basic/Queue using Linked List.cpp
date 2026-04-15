#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
private:
    Node *front, *rear;
    int sz;

public:
    myQueue() {
        front = NULL;
        rear = NULL;
        sz = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node *newNode = new Node(x);

        if(isEmpty())
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }

        sz += 1;
    }

    void dequeue() {
        if(isEmpty())
            return;

        Node *temp = front;
        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;

        sz -= 1;
    }

    int getFront() {
        if(isEmpty())
            return -1;
        
        return front->data;
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
    myQueue q;
    vector<string> result;

    for (auto& query : queries) {
        int type = query[0];

        if (type == 1)
            q.enqueue(query[1]);
        else if (type == 2)
            q.dequeue();
        else if (type == 3)
            result.push_back(to_string(q.getFront()));
        else if (type == 4)
            result.push_back(q.isEmpty() ? "true" : "false");
        else if (type == 5)
            result.push_back(to_string(q.size()));
    }

    return result;
}