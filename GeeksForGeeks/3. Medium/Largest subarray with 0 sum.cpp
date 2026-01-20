#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int maxLength(vector<int>& arr) {
    unordered_map<int, int> mpp;
    int prefixSum = 0, maxLength = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Result Subarray starts from zero index
        if(prefixSum == 0)
            maxLength = (int) i + 1;
        else {
            if(mpp.find(prefixSum) != mpp.end())
                maxLength = max(maxLength, ((int)i - mpp[prefixSum]));
            else
                // Store first occurrence only (gives maximum length)
                mpp[prefixSum] = i;
        }
    }
    
    return maxLength;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout<<maxLength(arr);

    return 0;
}