#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
    
    sort(strs.begin(), strs.end());

    string first = strs[0], last = strs[strs.size() - 1], prefix = "";
    size_t minLength = min(first.size(), last.size());

    for(size_t i = 0; i < minLength; i++) {
        if(first[i] != last[i])
            break;
        
        prefix += first[i];
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    
    cout<<longestCommonPrefix(strs);

    return 0;
}