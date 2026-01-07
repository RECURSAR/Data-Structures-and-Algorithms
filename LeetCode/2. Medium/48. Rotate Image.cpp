#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // Transpose the matrix by Traversing Lower Triangle (Since Diagonal Elements remain same in Transpose)
    size_t n = matrix.size();   // Square matrix

    for(size_t i = 1; i < n; i++) {
        for(size_t j = 0; j < n; j++) {
            if(j < i)
                swap(matrix[i][j], matrix[j][i]);
            // Iterating after the diagonal element is reached is of no use so we skip the inner loop
            else
                break;
        }
    }

    // Reverse each row of transposed matrix to rotate the original array by 90 Degree
    // & is added so that row refers to the original row inside the matrix instead of making a copy
    for(auto &row : matrix)
        reverse(row.begin(), row.end());
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    rotate(matrix);

    for(auto row : matrix) {
        for(auto num : row)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}