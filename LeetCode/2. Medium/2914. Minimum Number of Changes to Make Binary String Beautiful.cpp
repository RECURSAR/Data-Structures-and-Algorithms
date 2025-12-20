#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minChanges(string s) {
    int changes = 0;

    for (int i = 0; i + 1 < s.length(); i += 2)
      if (s[i] != s[i + 1])
        changes += 1;

    return changes; 
}

int main() {
    string s = "10";

    cout<<minChanges(s);

    return 0;
}