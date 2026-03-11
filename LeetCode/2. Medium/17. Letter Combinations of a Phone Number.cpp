#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void findCombinations(int index, string current, string text[], vector<string> &result, string digits) {
    if(index == (int)digits.size()) {
        result.push_back(current);
        return;
    }

    int digit = digits[index] - '0';
    
    for(int i = 0; i < (int)text[digit].size(); i++)
        findCombinations(index + 1, current + text[digit][i], text, result, digits);
}

vector<string> letterCombinations(string digits) {
    string text[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result;

    findCombinations(0, "", text, result, digits);

    return result;
}

int main() {
    string digits = "23";
    
    vector<string> result = letterCombinations(digits);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}