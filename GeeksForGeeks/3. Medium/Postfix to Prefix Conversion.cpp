#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string postToPre(string post_exp) {
    stack<string> st;
    unordered_set<char> ops = {'+', '-', '*', '/', '%', '^'};

    for(size_t i = 0; i < post_exp.size(); i++) {
        char c = post_exp[i];

        if(ops.find(c) == ops.end())
            st.push(string(1, c));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expression = c + op2 + op1;
            st.push(expression);
        }
    }

    return st.top();
}

int main() {
    string post_exp = "ABC/-AK/L-*";
    
    cout<<postToPre(post_exp);

    return 0;
}