#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int maxProfit(int index, vector<int> &nums, vector<int> &dp){
    if(index == 0)
        return nums[index];
    
    if(index < 0)
        return 0;

    if(dp[index] != -1)
        return dp[index];

    int pick = maxProfit(index - 2, nums, dp) + nums[index];
    int pickNot = maxProfit(index - 1, nums, dp) + 0;
    
    return dp[index] = max(pick, pickNot);
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);

    int maxAmount = maxProfit(nums.size() - 1, nums, dp);

    return maxAmount;
}*/

// Tabulation
/*
int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];

    for(int i = 1; i < nums.size(); i++){
        int pick = nums[i];
        if(i > 1)
            pick += dp[i - 2];

        int pickNot = dp[i - 1] + 0;

        dp[i] = max(pick, pickNot);
    }

    return dp[nums.size() - 1];
}*/

// Tabulation + Space Optimization
int rob(vector<int> &nums) {
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < nums.size(); i++){
        int pick = nums[i];
        if(i > 1)
            pick += prev2;
        
        int pickNot = 0 + prev;

        int curr = max(pick, pickNot);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {
    vector<int> nums = {1,2,3,1};

    cout<<rob(nums);

    return 0;
}