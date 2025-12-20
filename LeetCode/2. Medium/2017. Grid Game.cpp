#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long gridGame(vector<vector<int>>& grid) {
    const int n = grid[0].size();
    long ans = LONG_MAX;
    long sumRow0 = accumulate(grid[0].begin(), grid[0].end(), 0L);
    long sumRow1 = 0;

    for (int i = 0; i < n; ++i) {
      sumRow0 -= grid[0][i];
      ans = min(ans, max(sumRow0, sumRow1));
      sumRow1 += grid[1][i];
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};

    cout<<gridGame(grid);

    return 0;
}