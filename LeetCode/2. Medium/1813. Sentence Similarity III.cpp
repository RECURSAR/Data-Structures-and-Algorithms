#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool areSentencesSimilar(string sentence1, string sentence2) {
    // Split sentences into words
    vector<string> s1, s2;
    string word;

    // Split sentence1
    stringstream ss1(sentence1);
    while (ss1 >> word) {
        s1.push_back(word);
    }

    // Split sentence2
    stringstream ss2(sentence2);
    while (ss2 >> word) {
        s2.push_back(word);
    }

    // Ensure s1 is the smaller sentence
    if (s2.size() < s1.size()) {
        swap(s1, s2);
    }

    int l1 = 0, l2 = 0;
    // Prefix comparison
    while (l1 < s1.size() && l2 < s2.size() && s1[l1] == s2[l2]) {
        l1++;
        l2++;
    }

    int r1 = s1.size() - 1, r2 = s2.size() - 1;
    // Suffix comparison
    while (r1 >= 0 && r2 >= 0 && s1[r1] == s2[r2]) {
        r1--;
        r2--;
    }

    // Check if all words in s1 are matched as prefix or suffix
    return l1 > r1;
}

int main() {
    string sentence1 = "My name is Haley", sentence2 = "My Haley";

    cout<<areSentencesSimilar(sentence1, sentence2);

    return 0;
}