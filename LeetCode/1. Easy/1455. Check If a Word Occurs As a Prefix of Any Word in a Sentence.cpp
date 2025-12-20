#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int isPrefixOfWord(string sentence, string searchWord) {
    int index = 1;  // 1-indexed result
    size_t pos = 0;

    while (pos < sentence.size()) {
        size_t nextSpace = sentence.find(' ', pos);
        string word = sentence.substr(pos, nextSpace - pos);

        // Check if the word starts with searchWord
        if (word.find(searchWord) == 0)
            return index;

        pos = (nextSpace == string::npos) ? sentence.size() : nextSpace + 1;
        ++index;
    }

    return -1;  
}

int main() {
    string sentence = "i love eating burger", searchWord = "burg";

    cout<<isPrefixOfWord(sentence, searchWord);

    return 0;
}