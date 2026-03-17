#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void dfs(int index, string expression, long long total, long long last, vector<string> &result, string &num, int target) {
    if(index == (int)num.size()) {
        if(total == target)
            result.push_back(expression);
        return;
    }

    for(int length = 1; length <= (int)num.size() - index; length++) {
        string part = num.substr(index, length);
        
        if(part.size() > 1 && part[0] == '0')
            break;

        // Convert the given string to integer value
        long long curr = stoll(part);

        if(index == 0)
            dfs(index + length, part, curr, curr, result, num, target);
        else {
            // Try +
            dfs(index + length, expression + "+" + part, total + curr, curr, result, num, target);

            // Try -
            dfs(index + length, expression + "-" + part, total - curr, -curr, result, num, target);

            // Try * - undo last, apply precedence
            dfs(index + length, expression + "*" + part, total - last + last * curr, last * curr, result, num, target);
        }
    }

}

vector<string> addOperators(string num, int target) {
    vector<string> result;

    dfs(0, "", 0, 0, result, num, target);

    return result;
}

int main() {
    string num = "123";
    int target = 6;
    
    vector<string> result = addOperators(num, target);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}