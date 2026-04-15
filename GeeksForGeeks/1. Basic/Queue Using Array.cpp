#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class myQueue {
private:
    int capacity, front, rear, *queue;

public:
    myQueue(int n) {
        capacity = n;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % capacity);
    }

    void enqueue(int x) {
        if(isFull())
            return;

        if(isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;

        queue[rear] = x;
    }

    void dequeue() {
        if(isEmpty())
            return;

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
    }

    int getFront() {
        if(isEmpty())
            return -1;

        return queue[front];
    }

    int getRear() {
        if(isEmpty())
            return -1;

        return queue[rear];
    }
};

vector<string> processQueries(int n, vector<vector<int>> &queries);

int main() {
    int n = 3;
    vector<vector<int>> queries = {{1, 5}, {1, 3}, {1, 4}, {3}, {2}, {5}, {4}};

    vector<string> output = processQueries(n, queries);
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }

    return 0;
}

// Helper function to process queries
vector<string> processQueries(int n, vector<vector<int>> &queries) {
    myQueue q(n);
    vector<string> result;

    for (auto &query : queries) {
        int type = query[0];

        if (type == 1)
            q.enqueue(query[1]);     
        else if (type == 2)
            q.dequeue();       
        else if (type == 3)
            result.push_back(to_string(q.getFront()));      
        else if (type == 4)
            result.push_back(to_string(q.getRear()));     
        else if (type == 5)
            result.push_back(q.isEmpty() ? "true" : "false");      
        else if (type == 6)
            result.push_back(q.isFull() ? "true" : "false");
        
    }

    return result;
}