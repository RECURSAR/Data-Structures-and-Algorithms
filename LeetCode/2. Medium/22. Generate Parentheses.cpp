#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void constructValidParenthesis(vector<string> &result, string current, int open, int close, int n) {
    if((int)current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if(open < n)
        constructValidParenthesis(result, current + "(", open + 1, close, n);

    if(open > close)
        constructValidParenthesis(result, current + ")", open, close + 1, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;

    constructValidParenthesis(result, "", 0, 0, n);

    return result;
}

int main() {
    int n = 3;
    
    vector<string> result = generateParenthesis(n);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}