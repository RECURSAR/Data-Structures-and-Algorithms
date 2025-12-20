#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Hash map to store the grouped anagrams
    unordered_map<string, vector<string>> anagrams;

    // Iterate through each string in the input array
    for (string s : strs){
        // Create a character count array of size 26 (for each lowercase letter)
        vector<int> charCount(26, 0);
        for (char c : s){
            charCount[c - 'a']++;
        }

        // Convert the character count array to a string to use as the key
        string key;
        for (int count : charCount){
            // The "#" delimiter ensures that each count is distinctly separated, preventing ambiguity. 
            // For example, without the delimiter, the string "aaab" with a character count of [3, 1, 0, ...] might produce a key "310...". 
            // This could be misinterpreted (e.g., "31" could be taken as the count for 'a', which is incorrect). 
            // The delimiter ensures clarity: "3#1#0#...".
            key += to_string(count) + "#"; 
        }

        // Add the original string to the corresponding anagram group
        anagrams[key].push_back(s);
    }

    // Collect the grouped anagrams into the result vector
    vector<vector<string>> result;
    for (auto &it : anagrams){
        result.push_back(it.second);
    }

    for (int i = 0; i < result.size(); i++) {
    // Print each group of anagrams
    cout << "Group " << i + 1 << ": ";
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j];
        if (j < result[i].size() - 1) {
            cout << ", "; // Add comma between anagrams, but not after the last one
        }
    }
    cout << endl; // Newline after each group
}

    return 0;
}