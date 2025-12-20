#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    vector<string> result;
    
    // Helper lambda to count words in a sentence
    // Capture clause. It allows the lambda to access and modify variables from the surrounding scope by reference
    // const string &s is used so that the string s cannot be modified inside the lambda function
    auto countWords = [&](const string& s) {
        istringstream iss(s);
        string word;

        // The >> operator reads each word (delimited by spaces) from the sentence.
        while (iss >> word) 
            wordCount[word]++;
    };

    // Count words in both sentences
    countWords(s1);
    countWords(s2);

    // Find the words with count == 1 (uncommon words)
    for (const auto& entry : wordCount) {
        if (entry.second == 1)
            result.push_back(entry.first);
    }

    return result;
}

int main() {
    string s1 = "apple apple banana";
    string s2 = "banana orange";

    vector<string> uncommonWords = uncommonFromSentences(s1, s2);

    for (const string& word : uncommonWords) {
        cout << word << " ";
    }

    return 0;
}
