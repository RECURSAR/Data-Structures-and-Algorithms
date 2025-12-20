#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    long long sum = 0;
    int l = 0, ans = 1;

    for(size_t r = 0; r < nums.size(); r++) {
        sum += nums[r];

        // Cost :- (Last Number in window * Size of Window) - (Sum of Elements in the Window)
        // We expand window when cost <= k and shrink it when cost > k;
        while((long long)nums[(int)r] * (int(r) - l + 1) - sum > k) {
            sum -= nums[l];
            l += 1;
        }

        ans = max(ans, (int)r - l + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;
    
    cout<<maxFrequency(nums, k);

    return 0;
}