#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int helper(int i, vector<int> &nums, int target, unordered_map<string, int> &dp){
    if(i < 0)
        return target == 0 ? 1 : 0;
    
    string key = to_string(i) + "," + to_string(target);
    if(dp.find(key) != dp.end())
        return dp[key];

    int add = helper(i - 1, nums, target - nums[i], dp);
    int sub = helper(i - 1, nums, target + nums[i], dp);

    dp[key] = add + sub;
    return dp[key];
}

int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<string, int> dp;

    int ways = helper(nums.size() - 1, nums, target, dp);

    return ways;
}*/

// Tabulation (Already Space-Optimized)
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum || (sum + target) % 2 != 0) 
        return 0;

    int newTarget = (sum + target) / 2;
    vector<int> dp(newTarget + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
        for (int j = newTarget; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[newTarget];
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout<<findTargetSumWays(nums, target);

    return 0;
}