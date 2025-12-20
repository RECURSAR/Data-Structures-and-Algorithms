#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool evaluate(char op, const vector<bool>& vals) {
    if (op == '!') {
        return !vals[0];
    } else if (op == '&') {
        for (bool val : vals) {
            if (!val) return false;
        }
        return true;
    } else if (op == '|') {
        for (bool val : vals) {
            if (val) return true;
        }
        return false;
    }
    return false; // Should never reach here
}

bool parseBoolExpr(string expression) {
    stack<char> opStack; // Stack for operators
    stack<vector<bool>> valStack; // Stack for sub-expression values

    for (char ch : expression) {
        if (ch == 't') {
            if (!valStack.empty())
                valStack.top().push_back(true);
        } else if (ch == 'f') {
            if (!valStack.empty())
                valStack.top().push_back(false);
        } else if (ch == '!' || ch == '&' || ch == '|') {
            opStack.push(ch); // Push the operator to the stack
        } else if (ch == '(') {
            valStack.push(vector<bool>()); // Start a new sub-expression
        } else if (ch == ')') {
            // Process the sub-expression when we hit a ')'
            char op = opStack.top(); opStack.pop();
            vector<bool> vals = valStack.top(); valStack.pop();
            bool result = evaluate(op, vals);
            if (!valStack.empty()) // Push the result back to the current sub-expression
                valStack.top().push_back(result);
            else
                valStack.push(vector<bool>{result}); // Handle the case where valStack is empty
        }
    }

    // The final result is the only value left
    return !valStack.empty() && valStack.top().front();
}

int main() {
    string expression = "|(&(t,f,t),!(t))";

    cout << (parseBoolExpr(expression) ? "true" : "false") << endl;

    return 0;
}