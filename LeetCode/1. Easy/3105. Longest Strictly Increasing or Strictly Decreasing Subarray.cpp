#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    int ans = 1;
    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        increasing += 1;
        decreasing = 1;
      } 
      else if (nums[i] < nums[i - 1]) {
        decreasing += 1;
        increasing = 1;
      } 
      else {
        increasing = 1;
        decreasing = 1;
      }
      
      ans = max({ans, increasing, decreasing});
    }

    return ans;
}

int main() {
    vector<int> nums = {1,4,3,3,2};

    cout<<longestMonotonicSubarray(nums);

    return 0;
}