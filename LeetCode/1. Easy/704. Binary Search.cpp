#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Iterative Approach
/*
int search(vector<int>& nums, int target) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(nums[mid] == target)
            return mid;

        else if(nums[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
*/

// Recursive Approach
int binarySearch(vector<int> &nums, int target, int low, int high) {
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(nums[mid] == target)
        return mid;
    
    else if(nums[mid] < target)
        return binarySearch(nums, target, mid + 1, high);

    else
        return binarySearch(nums, target, low, mid - 1);
}

int search(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    cout<<search(nums, target);

    return 0;
}