#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;

    for (size_t i = 0; i < nums.size(); i++) {
        if (mpp.find(target - nums[i]) == mpp.end()) {
            mpp[nums[i]] = i;
        } else {
            return {int(i), mpp[target - nums[i]]};
        }
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);

    for(auto num : result)
        cout<<num<<" ";

    return 0;
}