#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int helper(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int i, int j) {
    if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = helper(obstacleGrid, dp, i - 1, j);
    int left = helper(obstacleGrid, dp, i, j - 1);
    
    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int uniquePaths = helper(obstacleGrid, dp, m - 1, n - 1);

    return uniquePaths;
}*/

// Tabulation
/*
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if(i == 0 && j == 0)
                dp[i][j] = 1;
            else {
                int up = 0;
                int left = 0;

                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}*/

// Tabulation + Space Optimization
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> prev(n, -1);

    for(int i = 0; i < m; i++){
        vector<int> curr(n, -1);
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1)
                curr[j] = 0;
            else if(i == 0 && j == 0)
                curr[j] = 1;
            else {
                int up = 0;
                int left = 0;

                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j - 1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePathsWithObstacles(obstacleGrid);

    return 0;
}