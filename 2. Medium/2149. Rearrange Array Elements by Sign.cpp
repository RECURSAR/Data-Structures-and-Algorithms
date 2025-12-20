#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int posIndex = 0, negIndex = 1;
    vector<int> result (nums.size(), 0);

    for(size_t i = 0; i < nums.size(); i++) {
        if(nums[i] > 0){
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        else {
            result[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    
    vector<int> result = rearrangeArray(nums);

    for(auto num : result)
        cout<<num<<" ";

    return 0;
}