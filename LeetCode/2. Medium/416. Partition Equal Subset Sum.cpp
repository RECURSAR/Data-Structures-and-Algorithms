#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
bool helper(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
    if(target == 0)
        return true;
    if(i == 0)
        return (nums[0] == target);
    if(dp[i][target] != -1)
        return dp[i][target];

    bool notTake = helper(i - 1, target, nums, dp);
    bool Take = false;
    if(target >= nums[i]) Take = helper(i - 1, target - nums[i], nums, dp);

    return dp[i][target] = notTake | Take;
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));

    if(sum % 2 != 0)
        return false;

    bool result = helper(nums.size() - 1, sum / 2, nums, dp);

    return result;
}*/

// Tabulation
/*
bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

    // Base case: sum of 0 is always possible
    for (int i = 0; i < nums.size(); i++)
        dp[i][0] = true;

    // Base case: only the first element can form a subset with sum equal to itself
    if (nums[0] <= target)
        dp[0][nums[0]] = true;

    for (int ind = 1; ind < nums.size(); ind++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[ind - 1][j];
            bool take = false;
            if (nums[ind] <= j)
                take = dp[ind - 1][j - nums[ind]];
            dp[ind][j] = take || notTake;
        }
    }

    return dp[nums.size() - 1][target];
}*/

// Tabulation + Space Optimization
bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    vector<bool> prev(target + 1, false);

    if(nums[0] <= target) prev[0] = true; // Base case: sum of 0 is always possible

    if (nums[0] <= target)
        prev[nums[0]] = true;

    for(int ind = 1; ind < nums.size(); ind++){
        vector<bool> curr(target + 1, false);
        curr[0] = true; // Base case: sum of 0 is always possible
        for(int j = 1; j <= target; j++){
            bool notTake = prev[j];
            bool Take = false;
            if(nums[ind] <= j) Take = prev[j - nums[ind]];
            curr[j] = Take | notTake;
        }
        prev = curr;
    }    

    return prev[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};

    canPartition(nums) ? cout<<"True" : cout<<"False";

    return 0;
}