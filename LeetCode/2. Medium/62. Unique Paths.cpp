#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Memoization
/*
int helper(int i, int j, vector<vector<int>> &dp) {
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = helper(i - 1, j, dp);
    int left = helper(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int paths = helper(m - 1, n - 1, dp);

    return paths;
}*/

// Tabulation
/*
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
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
int uniquePaths(int m, int n) {
    vector<int> prev(n, -1);
    
    for(int i = 0; i < m; i++){
        vector<int> curr(n, -1);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
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
    int m = 3, n = 7;

    cout<<uniquePaths(m, n);

    return 0;
}