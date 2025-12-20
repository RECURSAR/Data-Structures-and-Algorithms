#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int longestSubarray(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());  // Step 1: Find the maximum value
    int maxLength = 0, currentLength = 0;
    
    // Step 2: Find the longest contiguous subarray with elements equal to maxVal
    for (int num : nums) {
        if (num == maxVal) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else 
            currentLength = 0;  // Reset the current length if the number is not maxVal
    }
    
    return maxLength;
}

int main() {
    vector<int> nums = {1,2,3,3,2,2};

    cout << longestSubarray(nums);
    
    return 0;
}