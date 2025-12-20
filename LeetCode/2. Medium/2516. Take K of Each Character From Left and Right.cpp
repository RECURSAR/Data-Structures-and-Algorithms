#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int takeCharacters(string s, int k) {
    unordered_map<char, int> count;
    for (char c : s)
      ++count[c];

    // If it's impossible to take k of any character
    if (count['a'] < k || count['b'] < k || count['c'] < k)
      return -1;

    int n = s.size();
    int required = n - k;  // Minimum length of substring to leave behind
    int left = 0, right = 0;
    int maxLength = 0;  // Max length of substring that satisfies the condition

    unordered_map<char, int> window;
    while (right < n) {
      ++window[s[right]];
      ++right;

      // Shrink the window if it has more characters than allowed
      while (window['a'] > count['a'] - k ||
             window['b'] > count['b'] - k ||
             window['c'] > count['c'] - k) {
        --window[s[left]];
        ++left;
      }

      maxLength = max(maxLength, right - left);
    }

    return n - maxLength;       
}

int main() {
    string s = "aabaaaacaabc";
    int k = 2;

    cout<<takeCharacters(s, k);

    return 0;
}