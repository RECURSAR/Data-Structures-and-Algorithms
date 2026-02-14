#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> ROMANS = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int result = 0;

    for(size_t i = 0; i < s.size() - 1; i++) {
        if(ROMANS[s[i]] < ROMANS[s[i + 1]])
            result -= ROMANS[s[i]];
        else
            result += ROMANS[s[i]];
    }
    
    return result + ROMANS[s.back()];
}

int main() {
    string s = "III";
    
    cout<<romanToInt(s);

    return 0;
}