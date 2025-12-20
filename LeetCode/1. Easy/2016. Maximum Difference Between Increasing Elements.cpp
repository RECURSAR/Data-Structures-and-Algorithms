#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maximumDifference(vector<int>& nums) {
    int ans = -1;
    int mn = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > mn)
        ans = max(ans, nums[i] - mn);
      mn = min(mn, nums[i]);
    }

    return ans; 
}

int main() {
    vector<int> nums = {7,1,5,4};
    
    cout<<maximumDifference(nums);

    return 0;
}