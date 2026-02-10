#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), columns = matrix[0].size(),
        row = 0, column = columns - 1;

    while(row < rows && column >= 0) {
        if(matrix[row][column] == target)
            return true;
        else if(matrix[row][column] > target)
            column -= 1;
        else
            row += 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;

    searchMatrix(matrix, target) ? cout<<"True" : cout<<"False";

    return 0;
}