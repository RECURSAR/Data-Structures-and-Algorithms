#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
          nums[i] *= 2;
          nums[i + 1] = 0;
        }

        if (nums[i] > 0)
          swap(nums[i], nums[j++]);
      }
      
      return nums;
}

int main() {
    vector<int> nums = {1,2,2,1,1,0};

    vector<int> result = applyOperations(nums);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}