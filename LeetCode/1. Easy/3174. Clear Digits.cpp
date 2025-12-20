#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string clearDigits(string s) {
    string ans;

    for (const char c : s)
      if (isdigit(c))
        // Since `ans` only contains non-digit characters, popping the last
        // character is equivalent to deleting the closest non-digit character.
        ans.pop_back();
      else
        ans += c;

    return ans;
}

int main() {
    string s = "abc";

    cout<<clearDigits(s);

    return 0;
}