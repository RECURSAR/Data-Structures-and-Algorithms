#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maximumBeauty(vector<int>& nums, int k) {
    int ans = 0;

    std::sort(nums.begin(), nums.end());

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (nums[r] - nums[l] > 2 * k)
        ++l;
      ans = max(ans, r - l + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {4,6,1,2};
    int k = 2;

    cout<<maximumBeauty(nums, k);

    return 0;
}