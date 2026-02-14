#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string removeOuterParentheses(string s) {
    int level = 0;
    string result;

    for(auto ch : s) {
        if(ch == '(') {
            if(level > 0)
                result += ch;

            level += 1;
        }
        else if(ch == ')') {
            level -= 1;
            
            if(level > 0)
                result += ch;
        }
    }

    return result;
}

int main() {
    string s = "(()())(())";

    cout<<removeOuterParentheses(s);

    return 0;
}