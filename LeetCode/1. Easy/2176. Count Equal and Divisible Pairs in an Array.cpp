#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int countPairs(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, vector<int>> numToIndices;

    for (int i = 0; i < nums.size(); ++i)
      numToIndices[nums[i]].push_back(i);

    for (const auto& pair : numToIndices) {
      const auto& indices = pair.second;
      unordered_map<int, int> gcds;
      for (const int i : indices) {
        const int gcd_i = gcd(i, k);
        for (const auto& gcd_pair : gcds)
          if (gcd_i * gcd_pair.first % k == 0)
            ans += gcd_pair.second;
        ++gcds[gcd_i];
      }
    }

    return ans;   
}

int main() {
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;

    cout<<countPairs(nums, k);

    return 0;
}