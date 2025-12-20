#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    // row[rows] = {0} --> matrix[...][0]
    // column[columns] = {0} --> matrix[0][...]
    int rows = matrix.size(), columns = matrix[0].size();
    int col0 = 1;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] == 0) {
                // mark ith row
                matrix[i][0] = 0;
                
                // mark jth column
                if(j != 0)
                    matrix[0][j] = 0;
                else 
                    col0 = 0;
            }
        }
    }

    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < columns; j++) {
            if(matrix[i][j] != 0) {
                // Check for column & row
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0) {
        for(int j = 0; j < columns; j++)
            matrix[0][j] = 0;
    }

    if(col0 == 0) {
        for(int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    setZeroes(matrix);
    for(auto nums : matrix){
        for(auto num : nums)
            cout<<num<<" ";
        cout<<endl;
    }
        
    return 0;
}