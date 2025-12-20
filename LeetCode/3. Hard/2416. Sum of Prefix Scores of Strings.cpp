#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int count;  // To store the number of words passing through this node
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie and update counts
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count++;  // Increment count as this node is visited
        }
    }
    
    // Calculate the score of every prefix of the word
    int getPrefixScore(const string &word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            int idx = c - 'a';
            node = node->children[idx];
            score += node->count;  // Add the count of this node (prefix score)
        }
        return score;
    }
};

vector<int> sumPrefixScores(vector<string>& words) {
    Trie trie;
    
    // Insert all words into the Trie
    for (const string &word : words) {
        trie.insert(word);
    }
    
    // Calculate the prefix score for each word
    vector<int> result;
    for (const string &word : words) {
        result.push_back(trie.getPrefixScore(word));
    }
    
    return result;
}

int main() {
    vector<string> words = {"abc","ab","bc","b"};

    vector<int> sum = sumPrefixScores(words);
    for(auto it: sum)
        cout<<it;

    return 0;
}