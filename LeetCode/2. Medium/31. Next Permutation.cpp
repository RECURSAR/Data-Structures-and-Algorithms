#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int breakingPoint = -1;

    // 1. Find the first element from the right that is smaller than the element to its right
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            breakingPoint = i;
            break;
        }
    }

    // If no breaking point found, the array is in descending order, so reverse it
    if(breakingPoint == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // 2. Find the smallest element to the right of breaking point that is greater than nums[breakingPoint]
    for(int i = n - 1; i > breakingPoint; i--) {
        if(nums[i] > nums[breakingPoint]) {
            swap(nums[i], nums[breakingPoint]);
            break;
        }
    }

    // 3. Reverse the subarray to the right of breaking point
    reverse(nums.begin() + breakingPoint + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    nextPermutation(nums);

    for(auto num : nums)
        cout<<num<<" ";

    return 0;
}