#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int singleNumber(vector<int>& nums) {
    int missingNumber = 0;

    for(size_t i = 0; i < nums.size(); i++)
        missingNumber = missingNumber ^ nums[i];

    return missingNumber;
}

int main() {
    vector<int> nums = {2, 2, 1};

    cout<<singleNumber(nums);

    return 0;
}