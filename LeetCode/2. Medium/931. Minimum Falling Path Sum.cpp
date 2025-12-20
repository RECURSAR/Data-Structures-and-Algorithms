#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Memoization
/*
int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j < 0 || j >= matrix[0].size())
        return 1e9;
    if(i == 0)
        return matrix[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + helper(i - 1, j, matrix, dp);
    int upLeft = matrix[i][j] + helper(i - 1, j - 1, matrix, dp);
    int upRight = matrix[i][j] + helper(i - 1, j + 1, matrix, dp);
  
    return dp[i][j] = min(up, min(upLeft, upRight));
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int minSum = INT_MAX;
    for(int i = 0; i < n; i++)
        minSum = min(minSum, helper(n - 1, i, matrix, dp));
    
    return minSum;    
}*/

// Tabulation
/*
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j]; 
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int up = matrix[i][j] + dp[i - 1][j];

            int upLeft = matrix[i][j];
            if(j - 1 >= 0) upLeft += dp[i - 1][j - 1];
            else upLeft += 1e9;

            int upRight = matrix[i][j];
            if(j + 1 < n) upRight += dp[i - 1][j + 1];
            else upRight += 1e9;

            dp[i][j] = min(up, min(upLeft, upRight));
        }
    }

    int minSum = INT_MAX;
    for(int j = 0; j < n; j++)
        minSum = min(minSum, dp[n - 1][j]);
    
    return minSum;
}*/

// Tabulation + Space Optimization
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(n, -1);

    for(int j = 0; j < n; j++)
        prev[j] = matrix[0][j];
    
    for(int i = 1; i < n; i++){
        vector<int> curr(n, -1);
        for(int j = 0; j < n; j++){
            int up = matrix[i][j] + prev[j];
            
            int upLeft = matrix[i][j];
            if(j - 1 >= 0)  upLeft += prev[j - 1];
            else upLeft += 1e9;

            int upRight = matrix[i][j];
            if(j + 1 < n) upRight += prev[j + 1];
            else upRight += 1e9;

            curr[j] = min(up, min(upLeft, upRight));
        }

        prev = curr;
    }

    int minSum = INT_MAX;
    for(int j = 0; j < n; j++)
        minSum = min(minSum, prev[j]);
    
    return minSum;
}


int main() {
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};

    cout << minFallingPathSum(matrix);

    return 0;
}