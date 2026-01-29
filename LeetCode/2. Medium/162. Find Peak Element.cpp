#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low < high) {
        mid = low + (high - low) / 2;

        // Move to Left Half if Middle Element is greater than next
        if(nums[mid] > nums[mid + 1])
            high = mid;
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