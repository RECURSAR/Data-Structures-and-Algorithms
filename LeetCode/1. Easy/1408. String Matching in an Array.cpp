#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (const string& a : words)
      for (const string& b : words)
        if (a.length() < b.length() && b.find(a) != string::npos) {
          ans.push_back(a);
          break;
        }
    return ans;
}

int main() {
    vector<string> words = {"mass","as","hero","superhero"};

    vector<string> result = stringMatching(words);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}