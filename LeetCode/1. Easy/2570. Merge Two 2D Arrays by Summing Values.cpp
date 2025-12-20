#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void addCount(const vector<vector<int>>& nums, vector<int>& count) {
    for (const vector<int>& idAndVal : nums) {
      const int id = idAndVal[0];
      const int val = idAndVal[1];
      count[id] += val;
    }
}

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    constexpr int kMax = 1000;
    vector<vector<int>> ans;
    vector<int> count(kMax + 1);

    addCount(nums1, count);
    addCount(nums2, count);

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > 0)
        ans.push_back({i, count[i]});

    return ans;
}

int main() {
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}} , nums2 = {{1,4},{3,2},{4,1}};

    vector<vector<int>> result = mergeArrays(nums1, nums2);
    for(auto res : result)
        for(auto r : res)
            cout<<r<<" ";

    return 0;
}