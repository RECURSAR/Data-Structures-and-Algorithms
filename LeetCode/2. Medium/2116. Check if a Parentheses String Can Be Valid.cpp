#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool check(const string& s, const string& locked, bool isForward) {
    int changeable = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < s.length(); ++i) {
        const char c = s[i];
        const char lock = locked[i];
        if (lock == '0')
        ++changeable;

        else if (c == '(')
        ++l;

        else  // c == ')'
        ++r;

        if (isForward && changeable + l - r < 0)
        return false;

        if (!isForward && changeable + r - l < 0)
        return false;
    }

    return true;
}

bool canBeValid(string s, string locked) {
    if (s.length() % 2 == 1)
      return false;

    const bool leftToRightIsOkay = check(s, locked, true);

    std::reverse(s.begin(), s.end());
    std::reverse(locked.begin(), locked.end());

    const bool rightToLeftIsOkay = check(s, locked, false);
    return leftToRightIsOkay && rightToLeftIsOkay;
}

int main() {
    string s = "))()))", locked = "010100";

    canBeValid(s, locked) ? cout<<"True" : cout<<"False";

    return 0;
}