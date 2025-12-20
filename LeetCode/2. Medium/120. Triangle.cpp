#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int helper(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    // Starting from the beginning because if we start from end we would have to do 4 recursive calls in this test case
    if(i == triangle.size() - 1)
        return triangle[triangle.size() - 1][j];
    if(dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + helper(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + helper(i + 1, j + 1, triangle, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int minCost = helper(0, 0, triangle, dp);

    return minCost;
}*/

// Tabulation
/*
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[n - 1] = triangle[n - 1];    // Initializaing the last row of dp array with bottom row of triangle

    for(int i = n - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int down = triangle[i][j];
            int diagonal = triangle[i][j];

            if(i + 1 < n) down += dp[i + 1][j];
            if(i + 1 < n && j + 1 < n) diagonal += dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}*/

// Tabulation + Space Optimization
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev(n, -1);
    prev = triangle[n - 1];

    for(int i = n - 2; i >= 0; i--){
        vector<int> curr(n, -1);
        for(int j = i; j >= 0; j--){
            int down = triangle[i][j];
            int diagonal = triangle[i][j];

            if(i + 1 < n) down += prev[j];
            if(i + 1 < n && j + 1 < n) diagonal += prev[j + 1];

            curr[j] = min(down, diagonal);
        }

        prev = curr;
    }

    return prev[0];
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

    cout<<minimumTotal(triangle);

    return 0;
}