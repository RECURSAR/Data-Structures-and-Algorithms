#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool search(vector<int>& nums, int target) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return true;
        
        // Edge Case : All 3 numbers are equal, so we can't determine which side is sorted
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low += 1;
            high -= 1;
            continue;
        }

        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if(nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    search(nums, target) ? cout<<"True" : cout<<"False";

    return 0;
}