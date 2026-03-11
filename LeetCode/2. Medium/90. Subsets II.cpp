#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void findSubsets(int index, vector<int> current, vector<vector<int>>& result, vector<int>& nums) {
    result.push_back(current);

    for(int i = index; i < (int)nums.size(); i++) {
        if(i > index && nums[i] == nums[i - 1])
            continue;
        
        current.push_back(nums[i]);
        findSubsets(i + 1, current, result, nums);
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());
    findSubsets(0, {}, result, nums);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(nums);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}