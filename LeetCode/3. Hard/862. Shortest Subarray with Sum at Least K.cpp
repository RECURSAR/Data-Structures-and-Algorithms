#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = n + 1;
    deque<int> dq;
    vector<long> prefix{0};

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + nums[i]);

    for (int i = 0; i < n + 1; ++i) {
      while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
        ans = min(ans, i - dq.front()), dq.pop_front();

      while (!dq.empty() && prefix[i] <= prefix[dq.back()])
        dq.pop_back();
        
      dq.push_back(i);
    }

    return ans <= n ? ans : -1;   
}

int main() {
    vector<int> nums = {1};
    int k = 1;

    cout<<shortestSubarray(nums, k);

    return 0;
}