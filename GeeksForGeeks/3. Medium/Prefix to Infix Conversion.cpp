#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
string preToInfix(string pre_exp) {
    stack<string> st;
    unordered_set<char> ops = {'+', '-', '*', '/', '%', '^'};
    
    for(int i = pre_exp.size(); i >= 0; i--) {
        char c = pre_exp[i];
        
        if(ops.find(c) == ops.end())
            st.push(string(1, c));
        else {
            string left = st.top(); st.pop();
            string right = st.top(); st.pop();
            
            string expression = "(" + left + c + right + ")";
            st.push(expression);
        }
    }
    
    return st.top();
}

int main() {
    string pre_exp = "*-A/BC-/AKL";

    cout<<preToInfix(pre_exp);

    return 0;
}