#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> result;

    if (words.empty()) 
        return result;

    result.push_back(words[0]);

    for (int i = 1; i < words.size(); ++i) {
        if (groups[i] != groups[i-1]) {
            result.push_back(words[i]);
        }
    }
    
    return result;
}

int main() {
    vector<string> words = {"e","a","b"};
    vector<int> groups = {0,0,1};
    
    vector<string> result = getLongestSubsequence(words, groups);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}