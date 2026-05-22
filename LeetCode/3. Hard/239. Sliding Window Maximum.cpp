#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;

    for(int i = 0; i < result.size(); i++) {
        // Remove Expired Element from Front
        if(!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        
        // Remove Smaller Elements from Back
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        // Push Current Index to Back
        dq.push_back(i);

        // If window if formed record max
        if(i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(nums, k);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}