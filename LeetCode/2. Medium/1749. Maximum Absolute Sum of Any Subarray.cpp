#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0;
    int maxPrefix = 0;
    int minPrefix = 0;

    for (const int num : nums) {
      sum += num;
      maxPrefix = max(maxPrefix, sum);
      minPrefix = min(minPrefix, sum);
    }

    return maxPrefix - minPrefix;
}

int main() {
    vector<int> nums = {1,-3,2,3,-4};

    cout<<maxAbsoluteSum(nums);

    return 0;
}