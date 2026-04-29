#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string preToPost(string pre_exp) {
    stack<string> st;
    unordered_set<char> ops = {'+', '-', '*', '/', '%', '^'};
    
    for(int i = pre_exp.size() - 1; i >= 0; i--) {
        char c = pre_exp[i];

        if(ops.find(c) == ops.end())
            st.push(string(1, c));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expression = op1 + op2 + c;

            st.push(expression);
        }
    }

    return st.top();
}

int main() {
    string pre_exp = "*-A/BC-/AKL";
    
    cout<<preToPost(pre_exp);

    return 0;
}