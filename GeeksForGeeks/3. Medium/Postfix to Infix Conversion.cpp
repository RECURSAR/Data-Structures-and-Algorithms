#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string postToInfix(string &exp) {
    stack<string> st;
    unordered_set<char> ops = {'+', '-', '*', '/', '%', '^'};

    for(size_t i = 0; i < exp.size(); i++) {
        char c = exp[i];

        if(ops.find(c) == ops.end())
            st.push(string(1, c));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expression = "(" + op2 + c + op1 + ")";
            st.push(expression);
        }
    }

    return st.top();
}


int main() {
    string exp = "ab*c+";

    cout<<postToInfix(exp);

    return 0;
}