#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int longestSquareStreak(vector<int>& nums) {
    // Remove duplicates
    unordered_set<int> unique_nums(nums.begin(), nums.end());
    nums.assign(unique_nums.begin(), unique_nums.end());

    // Sort in descending order
    sort(nums.begin(), nums.end(), greater<int>());

    const int maxNum = *max_element(nums.begin(), nums.end());
    // dp[i] := the longest square streak starts with i
    vector<int> dp(maxNum + 1);

    for (const int num : nums) {
        dp[num] = 1;
        const long squaredNum = static_cast<long>(num) * num;
        if (squaredNum <= maxNum)
            dp[num] += dp[squaredNum];
    }

    const int ans = *max_element(dp.begin(), dp.end());
    return ans < 2 ? -1 : ans;
}

int main(){
    vector<int> nums = {4, 3, 6, 16, 2};

    cout << longestSquareStreak(nums);

    return 0;
}