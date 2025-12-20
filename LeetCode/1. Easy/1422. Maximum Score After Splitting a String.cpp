#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxScore(string s) {
    int ans = 0;
    int zeros = 0;
    int ones = std::count(s.begin(), s.end(), '1');

    for (int i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == '0')
        ++zeros;
      else
        --ones;
      ans = max(ans, zeros + ones);
    }

    return ans;    
}

int main() {
    string s = "011101";

    cout<<maxScore(s);

    return 0;
}