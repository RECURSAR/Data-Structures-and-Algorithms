#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
        
    // Step 1: Precompute the maximum values from the right
    vector<int> max_right(n);
    max_right[n - 1] = nums[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        max_right[i] = max(nums[i], max_right[i + 1]);
    }
    
    // Step 2: Find the maximum ramp width
    int res = 0;
    int l = 0;
    
    for (int r = 0; r < n; ++r) {
        // Move left pointer until nums[l] <= max_right[r]
        while (l < r && nums[l] > max_right[r]) {
            l++;
        }
        // Calculate and update the maximum ramp width
        if (l < r) {
            res = max(res, r - l);
        }
    }
    
    return res;
}

int main() {
    vector<int> nums = {6,0,8,2,1,5};

    cout<<maxWidthRamp(nums);

    return 0;
}