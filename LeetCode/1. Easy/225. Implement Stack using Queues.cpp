#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// 1 Queue, Push Costly
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        // Rotate all the elements at the back so that x ends up at front
        int sz = q.size();
        for(int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// 2 Queue, Pop Costly
// class MyStack {
//     private:
//         queue<int> q1, q2;

//     public:
//         MyStack() {
            
//         }
        
//         void push(int x) {
//             q1.push(x);
//         }
        
//         int pop() {
//             while(q1.size() > 1) {
//                 q2.push(q1.front());
//                 q1.pop();
//             }

//             int val = q1.front();
//             q1.pop();
//             swap(q1, q2);   // q2 becomes new q1
//             return val;
//         }
        
//         int top() {
//             while(q1.size() > 1) {
//                 q2.push(q1.front());
//                 q1.pop();
//             }

//             int val = q1.front();
//             q2.push(q1.front());    // Put to q1 before emptying
//             q1.pop();
//             swap(q1, q2);
//             return val;
//         }
        
//         bool empty() {
//             return q1.empty();
//         }
// };

vector<string> processQueries(vector<vector<int>>& queries);

int main() {
    vector<vector<int>> queries = {{1, 1}, {1, 2}, {3}, {2}, {4}};

    vector<string> output = processQueries(queries);
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}

vector<string> processQueries(vector<vector<int>>& queries) {
    MyStack s;
    vector<string> result;

    for (auto& query : queries) {
        int type = query[0];

        if (type == 1)
            s.push(query[1]);
        else if (type == 2)
            result.push_back(to_string(s.pop()));
        else if (type == 3)
            result.push_back(to_string(s.top()));
        else if (type == 4)
            result.push_back(s.empty() ? "true" : "false");
    }

    return result;
}