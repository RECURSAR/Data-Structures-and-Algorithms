#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> mpp;
    int count = 0;

    for(auto it: allowed)
        mpp.insert(it);
    
    for(auto word: words){
        bool isConsistent = true;

        for(auto c: word){
            // Check if character c is not in the set
            if(mpp.find(c) == mpp.end()){
                isConsistent = false;
                break;
            }
        }

        if(isConsistent)
            count++;
    }
    
    return count;
};

int main()
{
    string allowed = "ab";
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    cout<<countConsistentStrings(allowed, words);

    return 0;
}