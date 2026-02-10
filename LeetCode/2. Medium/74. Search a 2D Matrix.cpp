#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Better Approach
/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), columns = matrix[0].size(),
        low = 0, mid = 0, high = rows - 1,
        targetRow = -1;
    
    // Finding Row
    while(low <= high) {
        mid = low + (high - low) / 2;

        if(matrix[mid][0] <= target && target <= matrix[mid][columns - 1]) {
            targetRow = mid;
            break;
        }
        else if(matrix[mid][columns - 1] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(targetRow == -1)
        return false;
    
    low = 0, high = columns - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;

        if(matrix[targetRow][mid] == target)
            return true;
        else if(matrix[targetRow][mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}
*/

// Optimal Approach - In One Single Loop
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), columns = matrix[0].size(),
        low = 0, mid = 0, high = rows * columns - 1,
        row = 0, column = 0;
    
    while(low <= high) {
        mid = low + (high - low) / 2;

        row = mid / columns;
        column = mid % columns;

        if(matrix[row][column] == target)
            return true;
        else if(matrix[row][column] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    searchMatrix(matrix, target) ? cout<<"True" : cout<<"False";

    return 0;
}