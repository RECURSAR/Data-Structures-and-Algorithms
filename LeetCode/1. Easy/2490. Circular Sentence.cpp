#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

/*bool isCircularSentence(string sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;

    // Splitting sentence into words
    while(ss >> word)           // >> is extraction operator and extracts words
        words.push_back(word);
    
    // Check if sentence is circular
    for(int i = 0; i < words.size(); i++){
        string current_word = words[i];
        string next_word = words[(i + 1) % words.size()];
        if(current_word.back() != next_word.front())
            return false;
    }

    return true;
}*/

// OR

bool isCircularSentence(string sentence) {
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
            return false;
    }
    
    return sentence.front() == sentence.back();
}

int main() {
    string sentence = "leetcode exercises sound delightful";

    isCircularSentence(sentence) ? cout<<"True" : cout<<"False";

    return 0;
}