#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int largestRectangleArea(vector<int> &height) {
    int result = 0, n = height.size();
    stack<int> st;

    height.push_back(0);

    for(int i = 0; i < (int)height.size(); i++) {
        while(!st.empty() && height[st.top()] >= height[i]) {
            int mid = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = i - left - 1;

            result = max(result, height[mid] * width);
        }

        st.push(i);
    }

    height.pop_back();

    return result;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;

    int m = matrix[0].size(), maxArea = 0;
    vector<int> height(m, 0);

    for(auto &row : matrix) {
        for(int i = 0; i < m; i++) {
            if(row[i] == '1')
                height[i] += 1;
            else
                height[i] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    cout<<maximalRectangle(matrix);

    return 0;
}