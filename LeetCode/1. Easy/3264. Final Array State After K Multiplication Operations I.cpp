#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    vector<int> ans(nums.size());
    using P = pair<int, int>;  // (nums[i], i)
    priority_queue<P, vector<P>, greater<>> minHeap;

    for (int i = 0; i < nums.size(); ++i)
      minHeap.emplace(nums[i], i);

    while (k-- > 0) {
      const auto p = minHeap.top();
      const int num = p.first;
      const int i = p.second;
      minHeap.pop();
      minHeap.emplace(num * multiplier, i);
    }

    while (!minHeap.empty()) {
      const auto p = minHeap.top();
      const int num = p.first;
      const int i = p.second;
      minHeap.pop();
      ans[i] = num;
    }

    return ans;
}

int main() {
    vector<int> nums = {2,1,3,5,6};
    int k = 5, multiplier = 2;

    vector<int> res = getFinalState(nums, k, multiplier);
    for(auto i : res)
        cout<<i<<" ";

    return 0;
}