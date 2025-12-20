#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> ans;
    int start = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] != nums[i - 1] + 1)
        start = i;
      if (i >= k - 1)
        ans.push_back(i - start + 1 >= k ? nums[i] : -1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;

    vector<int> results = resultsArray(nums, k);
    for(auto res : results)
        cout<<res<<" ";

    return 0;
}