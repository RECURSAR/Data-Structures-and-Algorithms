#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;
    
    // Step 1: Compute the maximum OR of the entire array
    for (int num : nums) {
        maxOr |= num;
    }
    
    int count = 0;

    // Step 2: Helper function to count subsets with the same OR
    function<void(int, int)> dfs = [&](int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        // Include the current element in the subset
        dfs(index + 1, currentOr | nums[index]);
        
        // Exclude the current element from the subset
        dfs(index + 1, currentOr);
    };
    
    // Start the DFS from the first element with OR value 0
    dfs(0, 0);
    
    return count;
}

int main() {
    vector<int> nums = {3,1};

    cout<<countMaxOrSubsets(nums);

    return 0;
}