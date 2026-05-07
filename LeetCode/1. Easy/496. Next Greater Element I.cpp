#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Optimal Approach - Left to Right Traversal
/*
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int, int> nge;
    stack<int> st;

    for(int num : nums2) {
        while(!st.empty() && num > st.top()) {
            nge[st.top()] = num;
            st.pop();
        }

        st.push(num);
    }

    while(!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }

    for(int num : nums1)
        result.push_back(nge[num]);

    return result;
}
*/

// Optimal Apprioach - Right to Left Traversal
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int, int> nge;
    stack<int> st;

    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!st.empty() && nums2[i] >= st.top())
            st.pop();
        
        nge[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    for(int num : nums1)
        result.push_back(nge[num]);

    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}