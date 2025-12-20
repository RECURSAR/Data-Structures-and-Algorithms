#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end());
    int sum = 0;
    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (bannedSet.find(i) == bannedSet.end() && sum + i <= maxSum) {
            sum += i;
            ++count;
        }
    }

    return count;
}

int main() {
    vector<int> banned = {1,6,5};
    int n = 5, maxSum = 6;

    cout<<maxCount(banned, n, maxSum);

    return 0;
}