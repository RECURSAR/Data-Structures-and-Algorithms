#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 2; i < nums.size(); i += 3) {
      if (nums[i] - nums[i - 2] > k)
        return {};
      ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
    }

    return ans;
}

int main() {
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    
    vector<vector<int>> result = divideArray(nums, k);
    for(auto res : result){
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}