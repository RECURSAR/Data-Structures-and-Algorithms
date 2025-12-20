#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isVowel(char c) {
    static const string kVowels = "aeiou";
    return kVowels.find(c) != string::npos;
}

bool startsAndEndsWithVowel(const string& word) {
    return isVowel(word.front()) && isVowel(word.back());
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> ans;
    // prefix[i] := the number of the first i words that start with and end in a
    // vowel
    vector<int> prefix(words.size() + 1);

    for (int i = 0; i < words.size(); ++i)
      prefix[i + 1] += prefix[i] + startsAndEndsWithVowel(words[i]);

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      ans.push_back(prefix[r + 1] - prefix[l]);
    }

    return ans;
}

int main() {
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};

    vector<int> result = vowelStrings(words, queries);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}