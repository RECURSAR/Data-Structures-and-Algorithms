#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int backtrack(const string& s, int start, unordered_set<string>& seen) {
    if (start == s.length()) return 0;

    int maxSplits = 0;
    string current = "";

    // Try all substrings starting from 'start'
    for (int i = start; i < s.length(); ++i) {
        current += s[i];

        // If this substring is not in 'seen', we can split here
        if (seen.find(current) == seen.end()) {
            seen.insert(current);
            maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, seen));
            seen.erase(current); // Backtrack: remove the current substring
        }
    }

    return maxSplits;
}

int maxUniqueSplit(string s) {
    unordered_set<string> seen;
    return backtrack(s, 0, seen);
}

int main() {
    string s = "ababccc";

    cout<<maxUniqueSplit(s);

    return 0;
}