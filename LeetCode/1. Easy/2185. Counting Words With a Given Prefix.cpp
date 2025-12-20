#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int prefixCount(vector<string>& words, string pref) {
    return std::count_if(
        words.begin(), words.end(), [&](const string& word) { return word.find(pref) == 0; });
}

int main() {
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";

    cout<<prefixCount(words, pref);

    return 0;
}