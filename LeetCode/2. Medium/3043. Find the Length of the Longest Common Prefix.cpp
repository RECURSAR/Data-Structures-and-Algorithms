#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Function to find the longest common prefix between two strings
int commonPrefixLength(const string &a, const string &b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return i;  // Return the index where they differ
        }
    }
    return len;  // If one string is a prefix of the other
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    // Convert integers to strings and sort both arrays lexicographically
    vector<string> sArr1, sArr2;
    for (int x : arr1) sArr1.push_back(to_string(x));
    for (int y : arr2) sArr2.push_back(to_string(y));

    sort(sArr1.begin(), sArr1.end());
    sort(sArr2.begin(), sArr2.end());

    int longestPrefix = 0;
    int i = 0, j = 0;

    // Use two pointers to compare sorted arrays
    while (i < sArr1.size() && j < sArr2.size()) {
        // Compare the current strings from both sorted arrays
        int prefixLength = commonPrefixLength(sArr1[i], sArr2[j]);
        longestPrefix = max(longestPrefix, prefixLength);

        // Move pointers based on lexicographical order
        if (sArr1[i] < sArr2[j]) {
            i++;
        } else if (sArr1[i] > sArr2[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    return longestPrefix;
}

int main() {
    vector<int> arr1 = {1,10,100}, arr2 = {1000};

    cout<<longestCommonPrefix(arr1,arr2);

    return 0;
}