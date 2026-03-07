#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void generateStrings(string &s, int index, string current, vector<string> &result) {
    if(index == (int)s.size()) {
        if(!current.empty())
            result.push_back(current);
        return;
    }

    generateStrings(s, index + 1, current, result);
    generateStrings(s, index + 1, current + s[index], result);
}

vector<string> AllPossibleStrings(string s) {
    vector<string> result;

    generateStrings(s, 0, "", result);
    sort(result.begin(), result.end());

    return result;
}

int main() {
    string s = "abc";
    
    vector<string> result = AllPossibleStrings(s);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}