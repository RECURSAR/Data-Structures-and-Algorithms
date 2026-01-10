#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    int val;

    for(int r = 0; r < numRows; r++) {
        result.push_back(vector<int>(r + 1, 1));    // Inserting new row and initializing it with 1

        // Due to symmetry we will only go till the midpoint of each row
        for(int c = 1; c <= r / 2; c++) {
            val = result[r - 1][c - 1] + result[r - 1][c];
            result[r][c] = val;
            result[r][r - c] = val; // Populating the values after midpoint with the same val since they will be same by virtue of symmetry
        }
    }

    return result;
};

int main() {
    int numRows = 5;
    
    vector<vector<int>> result = generate(numRows);

    for(auto row : result) {
        for(auto num : row)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}