#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 1;

    for(size_t i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k += 1;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {1, 1, 2};
    
    int k = removeDuplicates(nums);

    for(int i = 0; i < k; i++)
        cout<<nums[i]<<" ";

    return 0;
}