#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    long totalSum = 0;
    
    // Calculate total sum of the array
    for (int num : nums) {
        totalSum += num;
    }
    
    // Target is the remainder we need to remove
    int target = totalSum % p;
    if (target == 0) return 0;  // The total sum is already divisible by p
    
    unordered_map<int, int> prefixMap;
    prefixMap[0] = -1;  // To handle the case where the valid subarray starts from index 0
    int currentPrefixSum = 0;
    int minLength = n;
    
    for (int i = 0; i < n; ++i) {
        currentPrefixSum = (currentPrefixSum + nums[i]) % p;
        
        // Find the remainder we want to match
        int requiredRemainder = (currentPrefixSum - target + p) % p;
        
        // Check if we have seen the required remainder before
        if (prefixMap.find(requiredRemainder) != prefixMap.end()) {
            int prevIndex = prefixMap[requiredRemainder];
            minLength = min(minLength, i - prevIndex);
        }
        
        // Store the current prefix sum mod p
        prefixMap[currentPrefixSum] = i;
    }
    
    // If minLength wasn't updated, it means no valid subarray was found
    return minLength == n ? -1 : minLength;
}

int main() {
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << "Minimum length of subarray to remove: " << minSubarray(nums, p) << endl;

    vector<int> nums2 = {6, 3, 5, 2};
    int p2 = 9;
    cout << "Minimum length of subarray to remove: " << minSubarray(nums2, p2) << endl;

    return 0;
}