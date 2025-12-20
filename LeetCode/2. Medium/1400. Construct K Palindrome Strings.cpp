#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canConstruct(string s, int k) {
    // If |s| < k, we cannot construct k strings from the s.
    if (s.length() < k)
      return false;

    bitset<26> odd;

    for (const char c : s)
      odd.flip(c - 'a');

    // If the number of letters that have odd counts > k, the minimum number of
    // palindromic strings we can construct is > k.
    return odd.count() <= k;
}

int main() {
    string s = "annabelle";
    int k = 2;

    canConstruct(s, k) ? cout<<"True" : cout<<"False";

    return 0;
}