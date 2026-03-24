#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using Recursion + Backtracking
/*
void generateSubsets(int index, vector<int> &nums, vector<int> current, vector<vector<int>> &result) {
    if(index == (int)nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Include the number at the current index
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, result);

    // Skip the element at current index
    current.pop_back();
    generateSubsets(index + 1, nums, current, result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;

    generateSubsets(0, nums, {}, result);

    return result;
}
*/

// Using Bit Manipulation
vector<vector<int>> subsets(vector<int>& nums) {
    int bits = nums.size();
    vector<vector<int>> result;

    for(int i = 0; i < pow(2, bits); i++) {
        vector<int> subset;
        for(int j = 0; j < bits; j++) {
            if(i & (1 << j))    // Checking if jth bit is set
                subset.push_back(nums[j]);
        }

        result.push_back(subset);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = subsets(nums);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}