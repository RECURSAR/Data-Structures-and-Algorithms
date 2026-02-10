#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size(), columns = mat[0].size(),
        low = 0, mid = 0, high = columns - 1,
        maxRow = 0, leftValue = 0, rightValue = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        maxRow = 0;
        for(int i = 0; i < rows; i++) {
            if(mat[i][mid] > mat[maxRow][mid])
                maxRow = i;
        }

        leftValue = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : 1;
        rightValue = (mid + 1 < columns) ? mat[maxRow][mid + 1] : -1;

        if(mat[maxRow][mid] > leftValue && mat[maxRow][mid] > rightValue)
            return {maxRow, mid};
        else if(rightValue > mat[maxRow][mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    
    vector<int> result = findPeakGrid(mat);
    for(auto num : result)
        cout<<num<<" ";

    return 0;
}