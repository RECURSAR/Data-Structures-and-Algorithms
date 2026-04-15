#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else {
            if(st.empty())
                return false;
            
            char top = st.top();
            st.pop();

            if(top == '(' && s[i] != ')')
                return false;
            if(top == '{' && s[i] != '}')
                return false;
            if(top == '[' && s[i] != ']')
                return false;
        }
    }

    return st.empty();
}

int main() {
    string s = "()";
    
    isValid(s) ? cout<<"True" : cout<<"False";

    return 0;
}