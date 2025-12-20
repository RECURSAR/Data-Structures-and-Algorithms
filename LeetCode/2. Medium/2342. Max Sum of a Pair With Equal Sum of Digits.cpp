#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
      digitSum += num % 10;
      num /= 10;
    }
    return digitSum;
}

int maximumSum(vector<int>& nums) {
    constexpr int kMax = 9 * 9;  // 999,999,999
    int ans = -1;
    vector<vector<int>> count(kMax + 1);

    for (const int num : nums)
      count[getDigitSum(num)].push_back(num);

    for (vector<int>& groupNums : count) {
      if (groupNums.size() < 2)
        continue;
      sort(groupNums.begin(), groupNums.end(), greater<>());
      ans = max(ans, groupNums[0] + groupNums[1]);
    }

    return ans;  
}

int main() {
    vector<int> nums = {18,43,36,13,7};

    cout<<maximumSum(nums);

    return 0;
}