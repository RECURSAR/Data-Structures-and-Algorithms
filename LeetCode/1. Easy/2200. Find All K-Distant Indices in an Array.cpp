#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;


vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    const int n = nums.size();
    vector<int> ans;

    for (int i = 0, j = 0; i < n; ++i) {
    // the first index j s.t. nums[j] == key and j >= i - k
        while (j < n && (nums[j] != key || j < i - k))
            ++j;
        if (j == n)
            break;
        if (abs(i - j) <= k)
            ans.push_back(i);
    }

    return ans;
}


int main() {
    vector<int> nums = {3,4,9,1,3,9,5};
    int key = 9, k = 1;

    vector<int> result = findKDistantIndices(nums, key, k);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}