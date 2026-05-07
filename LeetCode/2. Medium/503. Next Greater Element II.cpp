#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    unordered_map<int, int> nge;
    stack<int> st;

    for(int i = 2 * nums.size() - 1; i >= 0; i--) {
        int index = i % nums.size();

        while(!st.empty() && st.top() <= nums[index])
            st.pop();
        
        if(i < int(nums.size()))
            result[index] = st.empty() ? -1 : st.top();

        st.push(nums[index]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    
    vector<int> result = nextGreaterElements(nums);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}