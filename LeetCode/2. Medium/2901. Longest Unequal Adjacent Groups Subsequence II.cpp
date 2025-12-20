#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int hammingDist(const string& s1, const string& s2) {
    int dist = 0;

    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] != s2[i])
        ++dist;

    return dist;
}

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> ans;
    // dp[i] := the length of the longest subsequence ending in `words[i]`
    vector<int> dp(words.size(), 1);
    // prev[i] := the best index of words[i]
    vector<int> prev(words.size(), -1);

    for (int i = 1; i < words.size(); ++i)
      for (int j = 0; j < i; ++j) {
        if (groups[i] == groups[j])
          continue;

        if (words[i].length() != words[j].length())
          continue;

        if (hammingDist(words[i], words[j]) != 1)
          continue;
          
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }

    // Find the last index of the subsequence.
    int index = std::max_element(dp.begin(), dp.end()) - dp.begin();
    while (index != -1) {
      ans.push_back(words[index]);
      index = prev[index];
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<string> words = {"bab","dab","cab"};
    vector<int> groups = {1,2,2};
    
    vector<string> result = getWordsInLongestSubsequence(words, groups);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}