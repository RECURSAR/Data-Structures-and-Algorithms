#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    string result;
    int j = 0; // For Spaces

    for (int i = 0; i < s.size(); i++) {
        if (j < spaces.size() && i == spaces[j]) {
            result += ' ';
            j++;
        }
        result += s[i];
    }

    return result;
}

int main() {
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8,13,15};

    cout<<addSpaces(s, spaces);

    return 0;
}