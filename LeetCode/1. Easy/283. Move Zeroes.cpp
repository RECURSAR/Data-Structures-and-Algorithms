#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void moveZeroes(vector<int>& nums) {
    int left = 0;

    for(size_t right = 0; right < nums.size(); right++) {
        if(nums[right] != 0) {
            swap(nums[right], nums[left]);
            left += 1;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for(auto num : nums)
        cout<<num<<" ";

    return 0;
}