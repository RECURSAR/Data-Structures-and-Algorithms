#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int ans = 0;
    long prefix = 0;
    long suffix = accumulate(nums.begin(), nums.end(), 0L);

    for (int i = 0; i < nums.size() - 1; ++i) {
      prefix += nums[i];
      suffix -= nums[i];
      if (prefix >= suffix)
        ++ans;
    }

    return ans;     
}

int main() {
    vector<int> nums = {10,4,-8,7};

    cout<<waysToSplitArray(nums);

    return 0;
}