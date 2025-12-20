#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();
    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    // DP array to store the minimum extra characters for substring s[0:i]
    vector<int> dp(n + 1, 0);

    // Iterate through all characters of s
    for (int i = 1; i <= n; ++i) {
        // Initialize dp[i] with dp[i-1] + 1 (consider s[i-1] as extra
        // character)
        dp[i] = dp[i - 1] + 1;

        // Now check for each word in the dictionary
        for (int j = i - 1; j >= 0; --j) {
            string sub = s.substr(j, i - j);
            if (dict.find(sub) != dict.end()) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};

    cout<<minExtraChar(s,dictionary);
    
    return 0;
}