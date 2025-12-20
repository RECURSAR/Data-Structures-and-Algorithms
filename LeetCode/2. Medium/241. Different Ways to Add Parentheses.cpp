#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> diffWaysToCompute(string expression) {
    vector<int> result;

    for(int i = 0; i < expression.size(); i++){
        char c = expression[i];

        // If operator is encountered we split
        if(c == '+' || c == '-' || c == '*'){
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            // Combine these strings
            for(int l : left){
                for(int r : right){
                    if(c == '+')
                        result.push_back(l + r);
                    else if(c == '-')
                        result.push_back(l - r);
                    else if(c == '*')
                        result.push_back(l * r);
                }
            }
        }
    }

    // If string is a pure number
    if(result.empty())
        result.push_back(stoi(expression));

    return result;
}

int main() {
    string expression = "2-1-1";

    vector<int> possibilities = diffWaysToCompute(expression);

    for(auto possibility: possibilities)
        cout<<possibility;

    return 0;
}