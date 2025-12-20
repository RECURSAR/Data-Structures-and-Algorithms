#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;  // s1 cannot be a permutation of a substring of s2 if it's longer

    vector<int> s1Count(26, 0), windowCount(26, 0);

    // Count frequencies of characters in s1
    for (char c : s1) {
        s1Count[c - 'a']++;
    }

    // First window in s2 (size of s1)
    for (int i = 0; i < n1; i++) {
        windowCount[s2[i] - 'a']++;
    }

    // Slide the window over s2
    for (int i = n1; i < n2; i++) {
        // If the frequency of the current window matches s1's frequency, return true
        if (s1Count == windowCount) {
            return true;
        }

        // Slide the window: include s2[i] and exclude s2[i - n1]
        windowCount[s2[i] - 'a']++;             // Add the new character to the window
        windowCount[s2[i - n1] - 'a']--;        // Remove the character that is no longer in the window
    }

    // Check the last window
    return s1Count == windowCount;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl; // Expected output: true

    s1 = "ab";
    s2 = "eidboaoo";
    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl; // Expected output: false

    return 0;
}
