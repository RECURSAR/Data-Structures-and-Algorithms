#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    // If only one element
    if(nums.size() == 1)
        return nums[0];

    // If First Element is Unique
    if(nums[0] != nums[1])
        return nums[0];

    // If Last Element is Unique
    if(nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];

    int low = 1, mid = 0, high = nums.size() - 2;

    while(low <= high) {
        mid = low + (high - low) / 2;

        // Check if middle element is unique
        if((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1]))
            return nums[mid];
        
        // Mid is in left half (Pairing is Valid)
        if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
           (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
           low = mid + 1;   // Move to Right Half

        // Mid is in right half (Pairing Broken Earlier)
        else
            high = mid - 1; // Move to Left Half
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    
    cout<<singleNonDuplicate(nums);

    return 0;
}