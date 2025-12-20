#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    long ans = 0;
    long sum = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum * (r - l + 1) >= k)
        sum -= nums[l++];
      ans += r - l + 1;
    }

    return ans;
}

int main() {
    vector<int> nums = {2,1,4,3,5};
    long long k = 10;

    cout<<countSubarrays(nums, k);

    return 0;
}