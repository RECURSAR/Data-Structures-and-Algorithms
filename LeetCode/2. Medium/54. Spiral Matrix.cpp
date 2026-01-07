#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    size_t rows = matrix.size(), columns = matrix[0].size();
    vector<int> result;

    int top = 0, bottom = rows - 1, left = 0, right = columns - 1;

    // <= and >= are used so that row matrix and column matrix can be handled with values of top, bottom, left and right
    while(top <= bottom && left <= right) {
        // Left to Right
        for(int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        
        top += 1;

        // Top to Bottom
        for(int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        
        right -= 1;

        // If condition is put to handle single remaining row
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            
            bottom -= 1;
        }
        
        // If condition is put to handle single remaining column
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            
            left += 1;
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    vector<int> result = spiralOrder(matrix);

    for(auto num : result)
        cout<<num<<" ";

    return 0;
}