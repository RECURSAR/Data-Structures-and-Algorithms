#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minOperations(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;

    for (int i = 0; i + 2 < n; ++i)
      if (nums[i] == 0) {
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        ++ans;
      }

    return nums[n - 1] == 0 || nums[n - 2] == 0 ? -1 : ans;
}

int main() {
    vector<int> nums = {0,1,1,1,0,0};

    cout<<minOperations(nums);

    return 0;
}