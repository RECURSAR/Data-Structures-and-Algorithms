#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
    // value, list index, element index
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

    int k = nums.size();
    int left = nums[0][0], right = nums[0][0];
    for(int i = 0; i < k; i++){
        left = min(left, nums[i][0]);
        right = max(right, nums[i][0]);
        min_heap.push({nums[i][0], i, 0});
    }

    vector<int> result = {left, right};

    while(true){
        vector<int> current = min_heap.top();
        min_heap.pop();
        int val = current[0], list_idx = current[1], element_idx = current[2];

        // Update left boundary (smallest element in the heap)
        left = val;

        // If the current range is smaller than the previously found range, update the result
        if(right - left < result[1] - result[0]){
            result = {left, right};
        }

        // Move to the next element in the same list
        element_idx++;
        if(element_idx == nums[list_idx].size()){
            // If we have reached the end of one list, return the result
            return result;
        }

         // Get the next element from the same list and push it into the heap
        int next_val = nums[list_idx][element_idx];
        min_heap.push({next_val, list_idx, element_idx});

        // Update the right boundary (largest element seen so far)
        right = max({right, next_val});
    }
}

int main() {
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    
    vector<int> res = smallestRange(nums);
    for(auto it: res)
        cout<<it<<" ";
    
    return 0;
}