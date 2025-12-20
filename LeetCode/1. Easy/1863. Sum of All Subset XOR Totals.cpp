#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int subsetXORSum(const vector<int>& nums) {
    int all_or = 0;
    // Compute the bitwise OR of all elements
    for (int num : nums) {
        all_or |= num;
    }
    
    // Multiply by 2^(n-1) where n is the number of elements
    int n = nums.size();
    return all_or * (1 << (n - 1));
}

int main() {
    vector<int> nums = {1, 3};

    cout<<subsetXORSum(nums);

    return 0;
}