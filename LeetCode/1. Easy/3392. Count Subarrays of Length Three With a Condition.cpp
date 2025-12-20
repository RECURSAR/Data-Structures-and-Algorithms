#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countSubarrays(vector<int>& nums) {
    int ans = 0;

    for (int i = 1; i + 1 < nums.size(); ++i)
      if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
        ++ans;

    return ans;
}

int main() {
    vector<int> nums = {1,2,1,4,1};

    cout<<countSubarrays(nums);

    return 0;
}