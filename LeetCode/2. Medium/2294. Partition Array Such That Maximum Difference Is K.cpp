#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ans = 1;
    int mn = nums[0];

    for (int i = 1; i < nums.size(); ++i)
      if (mn + k < nums[i]) {
        ++ans;
        mn = nums[i];
      }

    return ans;
}

int main() {
    vector<int> nums = {3,6,1,2,5};
    int k = 2;

    cout<<partitionArray(nums, k);

    return 0;
}