#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string frequencySort(string s) {
    unordered_map<char,int> mpp;
    vector<vector<char>> bucket(s.size() + 1);
    string result;

    for(char ch : s)
        mpp[ch] += 1;    

    for(auto &p : mpp)
        bucket[p.second].push_back(p.first);

    for(int i = s.size(); i >= 1; i--) {
        for(char ch : bucket[i])
            result.append(i, ch);
    }

    return result;
}

int main() {
    string s = "tree";
    
    cout<<frequencySort(s);

    return 0;
}