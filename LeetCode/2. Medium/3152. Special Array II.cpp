#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<bool> ans;
    int id = 0;
    // parityIds[i] := the id of the parity group that nums[i] belongs to
    vector<int> parityIds = {id};

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] % 2 == nums[i - 1] % 2)
        ++id;
      parityIds.push_back(id);
    }

    for (const vector<int> query : queries) {
      const int from = query[0];
      const int to = query[1];
      ans.push_back(parityIds[from] == parityIds[to]);
    }

    return ans;
}

int main() {
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};

    vector<bool> result = isArraySpecial(nums, queries);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}