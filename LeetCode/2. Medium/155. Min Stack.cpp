#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {

    }
    
    void push(int val) {
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currentMin});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

vector<string> processQueries(vector<vector<int>>& queries);

int main() {
    vector<vector<int>> q = {{1, -2}, {1, 0}, {1, -3}, {4}, {2}, {3}, {4}};

    vector<string> out = processQueries(q);
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) cout << ", ";
    }

    return 0;
}

vector<string> processQueries(vector<vector<int>>& queries) {
    MinStack st;
    vector<string> result;

    for (auto &q : queries) {
        int type = q[0];

        if (type == 1)
            st.push(q[1]);
        else if (type == 2)
            st.pop();
        else if (type == 3)
            result.push_back(to_string(st.top()));
        else if (type == 4)
            result.push_back(to_string(st.getMin()));
    }

    return result;
}