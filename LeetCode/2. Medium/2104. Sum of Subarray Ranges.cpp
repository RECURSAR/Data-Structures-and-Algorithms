#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long result = 0;

    // Contribution of MINIMUMS (subtract) and MAXIMUMS (add)
    vector<long long> minLeft(n), minRight(n), maxLeft(n), maxRight(n);

    stack<int> st;
    
    // Previous Less Element (strict)
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        minLeft[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while (!st.empty()) 
        st.pop();

    // Next Less or Equal Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] > nums[i])
            st.pop();

        minRight[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    while (!st.empty()) 
        st.pop();

    // Previous Greater or Equal Element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

        maxLeft[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while (!st.empty()) 
        st.pop();

    // Next Greater Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] < nums[i])
            st.pop();

        maxRight[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    // result = (sum of max contributions) - (sum of min contributions)
    for (int i = 0; i < n; i++) {
        result += (long long)nums[i] * maxLeft[i] * maxRight[i];
        result -= (long long)nums[i] * minLeft[i] * minRight[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout<<subArrayRanges(nums)<<endl;

    return 0;
}