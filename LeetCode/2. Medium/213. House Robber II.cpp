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

    int take = maxProfit(index - 2, nums, dp) + nums[index];
    int takeNot = maxProfit(index - 1, nums, dp) + 0;

    return dp[index] = max(take, takeNot);
}

int rob(vector<int> &nums) {
    if(nums.size() == 1)
        return nums[0];

    vector<int> dp1(nums.size(), -1);
    vector<int> dp2(nums.size(), -1);

    // Exclude the first house
    vector<int> numsExcludingFirst(nums.begin() + 1, nums.end());
    int excludingFirst = maxProfit(numsExcludingFirst.size() - 1, numsExcludingFirst, dp1);

    // Exclude the last house
    vector<int> numsExcludingLast(nums.begin(), nums.end() - 1);
    int excludingLast = maxProfit(numsExcludingLast.size() - 1, numsExcludingLast, dp2);

    int maxAmount = max(excludingFirst, excludingLast);

    return maxAmount;
}*/

// Tabulation
/*
int rob(vector<int> &nums) {
    if (nums.size() == 1) 
        return nums[0]; 

    vector<int> dp1(nums.size(), 0);
    vector<int> dp2(nums.size(), 0);

    // Excluding the last house
    dp1[0] = nums[0];
    for (int i = 1; i < nums.size() - 1; i++) {
        int take = nums[i];
        if (i > 1)
            take += dp1[i - 2];
        
        int takeNot = dp1[i - 1] + 0;

        dp1[i] = max(take, takeNot);
    }

    // Excluding the first house
    dp2[1] = nums[1];
    for (int i = 2; i < nums.size(); i++) {
        int take = nums[i];
        if (i > 2)
            take += dp2[i - 2];
        
        int takeNot = dp2[i - 1] + 0;

        dp2[i] = max(take, takeNot);
    }

    return max(dp1[nums.size() - 2], dp2[nums.size() - 1]);
}*/

// Tabulation + Space Optimization
int rob(vector<int> &nums) {
    if (nums.size() == 1) 
        return nums[0]; 

    // Excluding the last house
    int prev1 = 0, prev2 = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        int take = nums[i] + prev2;
        int takeNot = prev1;

        int curr = max(take, takeNot);

        prev2 = prev1;
        prev1 = curr;
    }

    int excludeLast = prev1;

    // Excluding the first house
    prev1 = 0, prev2 = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        int take = nums[i] + prev2;
        int takeNot = prev1;

        int curr = max(take, takeNot);

        prev2 = prev1;
        prev1 = curr;
    }

    int excludeFirst = prev1;

    return max(excludeLast, excludeFirst);
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    cout<<rob(nums);

    return 0;
}