#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

    void transfer() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transfer();
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

vector<string> processQueries(vector<vector<int>>& queries);

int main() {
    vector<vector<int>> queries = {{1, 1}, {1, 2}, {3}, {2}, {4}};

    vector<string> output = processQueries(queries);
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }

    return 0;
}

vector<string> processQueries(vector<vector<int>>& queries) {
    MyQueue q;
    vector<string> result;

    for (auto& query : queries) {
        int type = query[0];

        if (type == 1)
            q.push(query[1]);
        else if (type == 2)
            result.push_back(to_string(q.pop()));
        else if (type == 3)
            result.push_back(to_string(q.peek()));
        else if (type == 4)
            result.push_back(q.empty() ? "true" : "false");
    }

    return result;
}