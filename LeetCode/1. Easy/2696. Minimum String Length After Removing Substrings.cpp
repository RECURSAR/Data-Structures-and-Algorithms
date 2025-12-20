#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minLength(string s){
    stack<char> st;

    for(char c : s){
        if(!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D')))
            st.pop();
        else
            st.push(c);
    }

    return st.size();
}

int main() {
    string s = "ABFCACDB";

    cout<<minLength(s);

    return 0;
}