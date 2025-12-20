#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      if (const auto it = count.find(num + 1); it != count.cend())
        ans = max(ans, freq + it->second);

    return ans;
}

int main() {
    vector<int> nums = {1,3,2,2,5,2,3,7};
    
    cout<<findLHS(nums);

    return 0;
}