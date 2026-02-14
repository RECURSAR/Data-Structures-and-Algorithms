#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using Map - Better Way
/*
bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;

    unordered_map<char, int> mpp;

    for(auto ch : s)
        mpp[ch] += 1;
    
    for(auto ch : t) {
        if(mpp.find(ch) == mpp.end() || mpp[ch] == 0)
            return false;
        
        mpp[ch] -= 1;
    }

    return true;
}
*/

// Using constant space
bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;

    int freq[26] = {0};
    int index = 0;

    for(int i = 0; i < s.size(); i++) {
        index = s[i] - 'a';
        freq[index] += 1;
    }

    for(int i = 0; i < t.size(); i++) {
        index = t[i] - 'a';
        freq[index] -= 1;
    }

    for(int i = 0; i < 26; i++)
        if(freq[i] != 0)
            return false;
    
    return true;
}

int main() {
    string s = "anagram", t = "nagaram";    

    isAnagram(s, t) ? cout<<"True" : cout<<"False";

    return 0;
}