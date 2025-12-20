#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;
    unordered_map<int, int> count;

    for (vector<int>& domino : dominoes) {
      int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
      ans += count[key];
      ++count[key];
    }

    return ans;
}

int main() {
    vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};

    cout<<numEquivDominoPairs(dominoes);

    return 0;
}