#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int firstGreaterEqual(const vector<int>& A, int target) {
    // Using std::lower_bound instead of ranges::lower_bound
    return lower_bound(A.begin(), A.end(), target) - A.begin();
}

vector<int> lengthOfLIS(vector<int> nums) {
    // tails[i] := the minimum tail of all the increasing subsequences having length i + 1
    vector<int> tails;
    // dp[i] := the length of LIS ending in nums[i]
    vector<int> dp;
    for (const int num : nums) {
        if (tails.empty() || num > tails.back())
            tails.push_back(num);
        else
            tails[firstGreaterEqual(tails, num)] = num;
        dp.push_back(tails.size());
    }
    return dp;
}

vector<int> reversed(const vector<int>& nums) {
    return {nums.rbegin(), nums.rend()};
}

int minimumMountainRemovals(vector<int>& nums) {
    const vector<int> l = lengthOfLIS(nums);
    const vector<int> r = reversed(lengthOfLIS(reversed(nums)));
    int maxMountainSeq = 0;

    for (int i = 0; i < nums.size(); ++i)
        if (l[i] > 1 && r[i] > 1)
            maxMountainSeq = max(maxMountainSeq, l[i] + r[i] - 1);

    return nums.size() - maxMountainSeq;
}

int main() {
    vector<int> nums = {1, 3, 1};

    cout << minimumMountainRemovals(nums);

    return 0;
}
