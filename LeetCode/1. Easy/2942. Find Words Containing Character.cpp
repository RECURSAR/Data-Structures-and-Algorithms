#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> indices;

    for(int i = 0; i < words.size(); i++) {
        if(words[i].find(x) != string::npos)
            indices.push_back(i);
    }

    return indices;
}

int main() {
    vector<string> words = {"leet","code"};
    char x = 'e';
    
    vector<int> result = findWordsContaining(words, x);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}