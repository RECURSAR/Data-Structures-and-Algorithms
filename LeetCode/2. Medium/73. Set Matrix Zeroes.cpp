#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void setZeroes(vector<vector<int>>& matrix) {
    size_t rows = matrix.size(), columns = matrix[0].size();

    // Here instead of using extra space i am using the first row and the first column
    // as the storage unit for counting 0's. But this will lead to overlapping of matrix[0][0].
    // So what we are doing is that we will use first column for counting row count and for counting
    // rows we will just use the first row starting from index 1 of column and for index 0 of column
    // we will store it in a separate variable
    int col0 = 1;

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            if(matrix[i][j] == 0) {
                // Marked the ith row
                matrix[i][0] = 0;

                // Marked the jth column
                if(j == 0)
                    col0 = 0;
                else
                    matrix[0][j] = 0;
            }
        }
    }

    // Filling Smaller matrix (Excluding First Row & First Column)
    for(size_t i = 1; i < rows; i++) {
        for(size_t j = 1; j < columns; j++) {
            if(matrix[i][j] != 0) {
                // Check the value of First Row & First Column
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    // Finally fill the First Row and the First Column
    // Populate 1st Row First since it is dependent on the value of col0
    if(matrix[0][0] == 0) {
        for(size_t j = 0; j < columns; j++) {
            if(matrix[0][j] != 0)
                matrix[0][j] = 0;
        }
    }
    
    // Now Populate the First Column
    if(col0 == 0) {
        for(size_t i = 0; i < rows; i++) {
            if(matrix[i][0] != 0)
                matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    setZeroes(matrix);

    for(auto row : matrix) {
        for(auto num : row) {
            cout<<num<<" ";
        }

        cout<<endl;
    }

    return 0;
}