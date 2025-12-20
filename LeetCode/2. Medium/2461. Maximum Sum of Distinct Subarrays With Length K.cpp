#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int left = 0;
    long long currSum = 0, maxSum = 0;
    unordered_set<int> st;

    for(int right = 0; right < nums.size(); right++){
        // Ensuring all elements in subarray are unique
        while(st.find(nums[right]) != st.end()){
            st.erase(nums[left]);
            currSum -= nums[left];
            left += 1;
        }

        st.insert(nums[right]);
        currSum += nums[right];

        if(right - left + 1 == k){
            maxSum = max(currSum, maxSum);

            // Removing lefmost element from map, also subtract it'ss value from the current sum and update the left pointer
            st.erase(nums[left]);
            currSum -= nums[left];
            left += 1;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;

    cout<<maximumSubarraySum(nums, k);

    return 0;
}