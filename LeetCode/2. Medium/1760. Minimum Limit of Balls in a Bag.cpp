#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;

    auto canDivide = [&](int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                operations += (balls - 1) / penalty; // Number of splits required
            }
        }
        return operations <= maxOperations;
    };

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDivide(mid)) {
            result = mid; // Try a smaller penalty
            right = mid - 1;
        } else {
            left = mid + 1; // Increase penalty
        }
    }

    return result;
}

int main() {
    vector<int> nums = {9}; 
    int maxOperations = 2;

    cout<<minimumSize(nums, maxOperations);

    return 0;
}