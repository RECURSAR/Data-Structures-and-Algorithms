#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Brute-Force Approach using map
// int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> mpp;

//     for(int i = 0; i < nums.size(); i++){
//         mpp[nums[i]] += 1;

//         if(mpp[nums[i]] > nums.size()/2)
//             return nums[i];
//     }

//     return -1;
// }

// OR

// Optimal Solution (Boyer-Moore Voting Algorithm)
int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;

    for(auto num : nums) {
        if(count == 0)
            candidate = num;

        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    cout<<majorityElement(nums);

    return 0;
}