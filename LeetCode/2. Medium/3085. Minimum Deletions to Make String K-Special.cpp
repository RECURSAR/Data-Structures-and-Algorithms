#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minimumDeletions(string word, int k) {
    int ans = INT_MAX;
    vector<int> count(26);

    for (const char c : word)
      ++count[c - 'a'];

    for (const int minFreq : count) {
      int deletions = 0;
      for (const int freq : count)
        if (freq < minFreq)  // Delete all the letters with smaller frequency.
          deletions += freq;
        else  // Delete letters with exceeding frequency.
          deletions += max(0, freq - (minFreq + k));
      ans = min(ans, deletions);
    }

    return ans;  
}

int main() {
    string word = "aabcaba";
    int k = 0;
    
    cout<<minimumDeletions(word, k);

    return 0;
}