#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numberOfSubstrings(string s) {
    int result = 0, left = 0;
    vector<int> freq(3);

    for(auto ch : s) {
        freq[ch - 'a'] += 1;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            freq[s[left] -'a'] -= 1;
            left += 1;
        }

        result += left;
    }

    return result;    
}

int main() {
    string s = "abcabc";

    cout<<numberOfSubstrings(s);

    return 0;
}