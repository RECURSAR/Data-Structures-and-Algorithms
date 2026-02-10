#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countLessEqual(vector<int> &row, int number) {
    return upper_bound(row.begin(), row.end(), number) - row.begin();
}

int median(vector<vector<int>> &mat) {
    int rows = mat.size(), columns = mat[0].size(),
        low = 0, mid = 0, high = 0,
        count = 0;
    
    low = mat[0][0];
    high = mat[0][columns - 1];
    
    for(int i = 0; i < rows; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][columns - 1]);
    }
    
    while(low < high) {
        mid = low + (high - low) / 2;
        
        count = 0;
        for(int i = 0; i < rows; i++)
            count += countLessEqual(mat[i], mid);
        
        if(count < (rows * columns + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    }
    
    return low;
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    cout<<median(mat);

    return 0;
}