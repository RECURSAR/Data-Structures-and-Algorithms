#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int missingNumber(vector<int>& nums) {
    // Sigma of n is (n * (n + 1)) / 2
    int expectedSum = (nums.size() * (nums.size() + 1)) / 2, originalSum = 0;

    for(auto num : nums)
        originalSum += num;

    return expectedSum - originalSum;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout<<missingNumber(nums);

    return 0;
}