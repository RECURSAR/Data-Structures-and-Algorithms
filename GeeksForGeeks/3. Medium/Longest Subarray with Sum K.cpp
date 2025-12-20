#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mpp;
    int lengthLongest = 0, prefixSum = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Case - 1
        // Subarray from index 0 to i has sum = k
        if(prefixSum == k)
            lengthLongest = i + 1;

        // Ensuring only unique values of prefixSum go into the map as earliest index gives the longest subarray later
        if(mpp.find(prefixSum) == mpp.end())
            mpp[prefixSum] = i;

        // Case - 2
        // If (prefixSum - k) exists, then subarray (mpp[prefixSum - k] + 1) to i has sum = k
        if(mpp.find(prefixSum - k) != mpp.end())
            lengthLongest = max(lengthLongest, int(i) - mpp[prefixSum - k]);
    }

    return lengthLongest;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout<<longestSubarray(arr, k);

    return 0;
}