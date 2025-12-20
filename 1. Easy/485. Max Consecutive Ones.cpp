#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0, localSum = 0;
    
    for(size_t i = 0; i < nums.size(); i++) {
        if(nums[i] == 1) {
            localSum += 1;
            maxOnes = max(maxOnes, localSum);
        }
        else
            localSum = 0;
    }

    return maxOnes;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout<<findMaxConsecutiveOnes(nums);

    return 0;
}