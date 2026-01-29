#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(low < high) {
        mid = low + (high - low) / 2;

        if(nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};

    cout<<findMin(nums);

    return 0;
}