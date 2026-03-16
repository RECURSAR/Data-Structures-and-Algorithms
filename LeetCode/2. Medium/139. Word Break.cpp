#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Recursive Solution
/*
bool breakString(string s, unordered_set<string> &dict) {
    if(s.empty())
        return true;
    
    string prefix = "", suffix = "";

    for(int i = 1; i <= (int)s.size(); i++) {
        prefix = s.substr(0, i);
        suffix = s.substr(i);

        if(dict.count(prefix) && breakString(suffix, dict))
            return true;
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    bool result = breakString(s, dict);

    return result;
}
*/

// Dynamic Programming
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for(int i = 1; i <= (int)s.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[s.size()];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    wordBreak(s, wordDict) ? cout<<"True" : cout<<"False";

    return 0;
}