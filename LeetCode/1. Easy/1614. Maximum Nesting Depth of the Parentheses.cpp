#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxDepth(string s) {
    int currentDepth = 0, result = 0;

    for(auto ch : s) {
        if(ch == '(')
            currentDepth += 1;
            
        else if(ch == ')') {
            result = max(result, currentDepth);
            currentDepth -= 1;
        }
    }

    return result;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    
    cout<<maxDepth(s);

    return 0;
}