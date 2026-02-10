#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low < high) {
        mid = low + (high - low) / 2;
        
        /*Case 1: nums[mid] > nums[mid + 1] (descending slope 📉)
            You are on a downhill
            A peak must exist on the left (or at mid)
            Move Left*/
        if(nums[mid] > nums[mid + 1])
            high = mid;

        /*Case 2: nums[mid] < nums[mid + 1] (ascending slope 📈)
            You are on an uphill
            A peak must exist on the right
            Move Right*/
        else 
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    
    cout<<findPeakElement(nums);

    return 0;
}