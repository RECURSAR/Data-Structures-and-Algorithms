#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxAdjacentDistance(vector<int>& nums) {
    int maxDist = INT_MIN;

    for(int i = 0; i < nums.size() - 1; i++) 
        maxDist = max(abs(nums[i] - nums[i + 1]), maxDist);
    
    maxDist = max(abs(nums[0] - nums[nums.size() - 1]), maxDist);

    return maxDist;
}

int main() {
    vector<int> nums = {1,2,4};
    
    cout<<maxAdjacentDistance(nums);

    return 0;
}