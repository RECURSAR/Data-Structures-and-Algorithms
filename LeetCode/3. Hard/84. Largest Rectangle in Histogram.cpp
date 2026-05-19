#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using minPrefix and minSuffix
/*
int largestRectangleArea(vector<int>& heights) {
    int result = 0;
    size_t n = heights.size();
    vector<int> minLeft(n), minRight(n);
    stack<int> st;

    // Min present on left
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        minLeft[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Min present on right
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        minRight[i] = st.empty() ? n : st.top();
        st.push(i);
    }


    for (int i = 0; i < n; i++) {
        int width = minRight[i] - minLeft[i] - 1;

        result = max(result, heights[i] * width);
    }

    return result;
}
*/

// Optimal Approach
int largestRectangleArea(vector<int>& heights) {
    int result = 0, n = heights.size();
    stack<int> st;

    heights.push_back(0);

    for(int i = 0; i < (int)heights.size(); i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            int mid = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = i - left - 1;

            result = max(result, heights[mid] * width);
        }

        st.push(i);
    }

    heights.pop_back();

    return result;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout<<largestRectangleArea(heights);

    return 0;
}