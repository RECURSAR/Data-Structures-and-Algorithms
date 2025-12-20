#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minOperations(vector<int>& nums, int k) {
    int ans = 0;
    priority_queue<long, vector<long>, greater<>> minHeap;

    for (const int num : nums)
      minHeap.push(num);

    while (minHeap.size() > 1 && minHeap.top() < k) {
      const int x = minHeap.top();
      minHeap.pop();
      const int y = minHeap.top();
      minHeap.pop();
      minHeap.push(min(x, y) * 2L + max(x, y));
      ++ans;
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    
    cout<<minOperations(nums, k);

    return 0;
}