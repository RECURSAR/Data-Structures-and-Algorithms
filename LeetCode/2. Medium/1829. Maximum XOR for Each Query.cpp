#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int>getMaximumXor(vector<int>& nums, int maximumBit) {
    const int mx = (1 << maximumBit) - 1;  // The maximum possible value with maximumBit bits
    vector<int> ans;  // To store the answers to each query
    int xors = 0;  // To store the cumulative XOR of elements in nums

    // Iterate over the array and calculate the XOR for each query
    for (const int num : nums) {
      xors ^= num;  // Update cumulative XOR
      ans.push_back(xors ^ mx);  // The best k to maximize XOR is xors ^ mx
    }

    reverse(ans.begin(), ans.end());  // Reverse the answer array to get the correct query order

    return ans;  // Return the answer array
}

int main() {
    vector<int> nums = {0,1,1,3};
    int maximumBit = 2;

    vector<int> answer = getMaximumXor(nums, maximumBit);
    for(auto ans : answer)
        cout<<ans<<" ";

    return 0;
}