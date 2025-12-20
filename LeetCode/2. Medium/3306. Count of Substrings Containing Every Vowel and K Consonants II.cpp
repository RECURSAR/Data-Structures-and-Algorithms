#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isVowel(char c) {
    // Replace string_view with standard string checking
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Return the number of substrings containing every vowel with at most k consonants.
long substringsWithAtMost(const string& word, int k) {
    if (k == -1)
    return 0;
    long res = 0;
    int vowels = 0;
    int uniqueVowels = 0;
    unordered_map<char, int> vowelLastSeen;

    for (int l = 0, r = 0; r < word.length(); ++r) {
    if (isVowel(word[r])) {
        ++vowels;
        // Rewritten without structured binding
        auto it = vowelLastSeen.find(word[r]);
        if (it == vowelLastSeen.end() || it->second < l)
        ++uniqueVowels;
        vowelLastSeen[word[r]] = r;
    }
    while (r - l + 1 - vowels > k) {
        if (isVowel(word[l])) {
        --vowels;

        if (vowelLastSeen[word[l]] == l)
            --uniqueVowels;
        }

        ++l;
    }
        if (uniqueVowels == 5) {
            // Find the minimum position among all vowels
            int minPos = word.length();
            if (vowelLastSeen.find('a') != vowelLastSeen.end())
            minPos = min(minPos, vowelLastSeen['a']);
            if (vowelLastSeen.find('e') != vowelLastSeen.end())
            minPos = min(minPos, vowelLastSeen['e']);
            if (vowelLastSeen.find('i') != vowelLastSeen.end())
            minPos = min(minPos, vowelLastSeen['i']);
            if (vowelLastSeen.find('o') != vowelLastSeen.end())
            minPos = min(minPos, vowelLastSeen['o']);
            if (vowelLastSeen.find('u') != vowelLastSeen.end())
            minPos = min(minPos, vowelLastSeen['u']);
            
            res += minPos - l + 1;
        }
    }
    return res;
}

long long countOfSubstrings(string word, int k) {
    return substringsWithAtMost(word, k) - substringsWithAtMost(word, k - 1);
}

int main() {
    string word = "aeioqq";
    int k = 1;

    cout<<countOfSubstrings(word, k);

    return 0;
}