#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;
        
        // Checking if Left Half is Sorted
        if(nums[low] <= nums[mid]) {
            // If target lies in the sorted left half, search there
            if(nums[low] <= target && target < nums[mid])
                high = mid - 1;
            // Else search in the right half
            else
                low = mid + 1;
        }
        
        // Right Half will be Sorted
        else {
            // If target lies in the sorted right half, search there
            if(nums[mid] < target && target <= nums[high])
                low = mid + 1;
            // Else search in the left half
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout<<search(nums, target);

    return 0;
}