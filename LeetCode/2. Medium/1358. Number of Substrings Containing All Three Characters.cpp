#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numberOfSubstrings(string s) {
    int ans = 0;
    vector<int> count(3);

    int l = 0;
    for (const char c : s) {
      ++count[c - 'a'];
      while (count[0] > 0 && count[1] > 0 && count[2] > 0)
        --count[s[l++] - 'a'];
      // s[0..r], s[1..r], ..., s[l - 1..r] are satified strings.
      ans += l;
    }

    return ans;    
}

int main() {
    string s = "abcabc";

    cout<<numberOfSubstrings(s);

    return 0;
}