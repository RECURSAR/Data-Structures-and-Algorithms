#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> ans;
    vector<int> arr(nums);
    nth_element(arr.begin(), arr.end() - k, arr.end());
    const int threshold = arr[arr.size() - k];
    const int larger =
        count_if(nums.begin(), nums.end(), [&](int num) { return num > threshold; });
    int equal = k - larger;

    for (const int num : nums)
      if (num > threshold) {
        ans.push_back(num);
      } else if (num == threshold && equal) {
        ans.push_back(num);
        --equal;
      }

    return ans;  
}

int main() {
    vector<int> nums = {2, 1, 3, 3};
    int k = 2;
    
    vector<int> result = maxSubsequence(nums, k);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}