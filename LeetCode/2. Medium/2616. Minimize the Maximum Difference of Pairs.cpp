#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Returns the number of pairs that can be obtained if the difference between
// each pair <= `maxDiff`.
int numPairs(const vector<int>& nums, int maxDiff) {
    int pairs = 0;
    for (int i = 1; i < nums.size(); ++i)
        // Greedily pair nums[i] with nums[i - 1].
        if (nums[i] - nums[i - 1] <= maxDiff) {
        ++pairs;
        ++i;
        }
    return pairs;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      const int m = (l + r) / 2;
      if (numPairs(nums, m) >= p)
        r = m;
      else
        l = m + 1;
    }

    return l;
}

int main() {
    vector<int> nums = {10,1,2,7,1,3};
    int p = 2;
    
    cout<<minimizeMax(nums, p);

    return 0;
}