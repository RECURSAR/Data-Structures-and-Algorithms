#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long countLess(const vector<int>& nums, int sum) {
    long res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
        while (i < j && nums[i] + nums[j] > sum)
        --j;
        res += j - i;
    }

    return res;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    // nums[i] + nums[j] == nums[j] + nums[i], so the condition that i < j
    // degrades to i != j and we can sort the array.
    sort(nums.begin(), nums.end());
    
    return countLess(nums, upper) - countLess(nums, lower - 1);
}

int main() {
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;

    cout<<countFairPairs(nums, lower, upper);

    return 0;
}