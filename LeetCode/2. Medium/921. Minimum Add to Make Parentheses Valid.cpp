#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// With Stack
/*
int minAddToMakeValid(string s){
    stack<char> st;
    int moves = 0;

    for(char c : s){
        if(c == '(')
            st.push(c);

        else{
            if(!st.empty())
                st.pop();

            // When ')' is more than '(' 
            else 
                moves++;
        }
    } 

    return moves + st.size();
}*/

// Without Stack
int minAddToMakeValid(string s){
    int balance = 0;
    int moves = 0;

    for(char c : s){
        if(c == '(')
            balance++;
        else 
            balance--;
        
        if(balance < 0){
            moves++;
            balance = 0;
        }
    } 

    return moves + balance;
}

int main(){
    string s = "())";

    cout<<minAddToMakeValid(s);

    return 0;
}