#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findDiff(vector<int>& arr) {
    unordered_map<int, int> freq;
    int maxFreq = INT_MIN, minFreq = INT_MAX;

    // Populating the map
    for(auto num : arr)
        freq[num] += 1;
    
    for(auto p : freq) {
        // The number with the largest frequency
        maxFreq = max(maxFreq, p.second);

        // The number with the lowest frequency
        minFreq = min(minFreq, p.second);
    }

    return (maxFreq - minFreq);
}

int main() {
    vector<int> arr = {1, 2, 2};

    cout<<findDiff(arr);

    return 0;
}