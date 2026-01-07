#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    int prefixSum = 0, totalSubarrays = 0, remove = 0;

    mpp[0] = 1;

    for(size_t i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        remove = prefixSum - k;
        
        totalSubarrays += mpp[remove];
        mpp[prefixSum] += 1;
    }

    return totalSubarrays;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    
    cout<<subarraySum(nums, k);

    return 0;
}