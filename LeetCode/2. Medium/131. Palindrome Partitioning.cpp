#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool checkPalindrome(int start, int end, string s) {
    while(start < end) {
        if(s[start] != s[end])
            return false;

        start += 1;
        end -= 1;
    }

    return true;
}

void findPalindromes(int index, vector<string> &partitions, vector<vector<string>> &result, string s) {
    if(index == (int)s.size()) {
        result.push_back(partitions);
        return;
    }

    for(int i = index; i < (int)s.size(); i++) {
        if(checkPalindrome(index, i, s)) {
            partitions.push_back(s.substr(index, i - index + 1));
            findPalindromes(i + 1, partitions, result, s);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> partitions = {};

    findPalindromes(0, partitions, result, s);

    return result;
}

int main() {
    string s = "aab";
    
    vector<vector<string>> result = partition(s);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}