#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void sortColors(vector<int>& nums) {
    // Dutch National Flag Problem
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low += 1;
            mid += 1;
        }
        else if(nums[mid] == 1) {
            mid += 1;
        }
        else {
            swap(nums[mid], nums[high]);
            high -= 1;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for(auto num: nums)
        cout<<num<<" ";

    return 0;
}