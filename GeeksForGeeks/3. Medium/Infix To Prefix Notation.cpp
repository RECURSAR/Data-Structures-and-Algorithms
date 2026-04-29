#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') 
        return 3;
    else if (c == '*' || c == '/') 
        return 2;
    else if (c == '+' || c == '-') 
        return 1;

    else return -1;
}

bool isRightAssociative(char c) {
    return (c == '^');
}

string infixToPrefix(string &s) {
    stack<char> st;
    string result = "";

    for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];

        if(isalnum(c))
            result += c;

        else if(c == ')')
            st.push(c);

        else if(c == '(') {
            while(!st.empty() && st.top() != ')') {
                result += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }

        else if(isOperator(c)) {
            while(!st.empty() && isOperator(st.top()) && 
            (precedence(st.top()) > precedence(c) || 
            (precedence(st.top()) == precedence(c) && isRightAssociative(c)))) {
                result += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "a*(b+c)/d";
    
    cout<<infixToPrefix(s);

    return 0;
}