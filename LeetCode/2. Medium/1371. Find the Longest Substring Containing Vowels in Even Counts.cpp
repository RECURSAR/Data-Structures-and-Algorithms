#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findTheLongestSubstring(string s) {
    int prefixXOR = 0; // Step 1: Initialize prefixXOR to track vowel counts

    // Step 2: Store the masks of all vowels in an array.
    int characterMap[26] = {0}; // Character map for all letters
    characterMap['a' - 'a'] = 1; // 'a' corresponds to bit 0
    characterMap['e' - 'a'] = 2; // 'e' corresponds to bit 1
    characterMap['i' - 'a'] = 4; // 'i' corresponds to bit 2
    characterMap['o' - 'a'] = 8; // 'o' corresponds to bit 3
    characterMap['u' - 'a'] = 16; // 'u' corresponds to bit 4
    
    // Step 3: Initialize mp to store the previous index with this prefixXOR value.
    vector<int> mp(32, -1); // Map for storing first occurrence of each prefixXOR
    int longestSubstring = 0; // Variable to track the longest valid substring

    for (int i = 0; i < s.length(); i++) {
        // Step 4: If the current character is a vowel, update prefixXOR.
        prefixXOR ^= characterMap[s[i] - 'a']; // Toggle corresponding bit for vowels
        
        // Step 5: If this prefixXOR hasn't been seen before, store its index.
        if (mp[prefixXOR] == -1 && prefixXOR != 0) 
            mp[prefixXOR] = i;

        // Step 6: If this prefixXOR has been seen before, calculate the substring length.
        longestSubstring = max(longestSubstring, i - mp[prefixXOR]);
    }

    // Step 7: Return the length of the longest valid substring
    return longestSubstring; 
}

int main() {
    string s = "eleetminicoworoep";

    cout<<findTheLongestSubstring(s)<<endl;

    return 0;
}