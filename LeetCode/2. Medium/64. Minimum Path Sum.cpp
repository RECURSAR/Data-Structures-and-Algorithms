#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    if(i == 0 && j == 0)
        return grid[0][0];
    if(i < 0 || j < 0)
        return 1e9;
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + helper(grid, i - 1, j, dp);
    int left = grid[i][j] + helper(grid, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int minSum = helper(grid, m - 1, n - 1, dp);

    return minSum;
}*/

// Tabulation
/*
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
                dp[0][0] = grid[0][0];
            else {
                int up = grid[i][j];
                if(i > 0) up += dp[i - 1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += dp[i][j - 1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[m - 1][n - 1];
}*/

// Tabulation + Space Optimization
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, -1);

    for(int i = 0; i < m; i++){
        vector<int> curr(n, -1);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
                curr[j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += curr[j - 1];
                else left += 1e9;

                curr[j] = min(up, left);
            }
        }
        
        prev = curr;
    }

    return prev[n - 1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    cout<<minPathSum(grid);

    return 0;
}