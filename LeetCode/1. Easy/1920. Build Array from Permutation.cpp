#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    const int n = nums.size();

    for (int i = 0; i < n; ++i)
      nums[i] += n * (nums[nums[i]] % n);

    for (int i = 0; i < n; ++i)
      nums[i] /= n;

    return nums;       
}

int main() {
    vector<int> nums = {0,2,1,5,3,4};

    vector<int> result = buildArray(nums);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}