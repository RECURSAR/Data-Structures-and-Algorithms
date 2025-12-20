#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = isWater.size();
    const int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (isWater[i][j] == 1) {
          q.emplace(i, j);
          ans[i][j] = 0;
        }

    while (!q.empty()) {
      const pair<int, int> p = q.front();
      const int i = p.first;
      const int j = p.second;
      q.pop();
      for (const auto& dir : dirs) {
        const int dx = dir[0];
        const int dy = dir[1];
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (ans[x][y] != -1)
          continue;
        ans[x][y] = ans[i][j] + 1;
        q.emplace(x, y);
      }
    }

    return ans;
}

int main() {
    vector<vector<int>> isWater = {{0,1},{0,0}};

    vector<vector<int>> result = highestPeak(isWater);
    for(auto res : result){
        for(auto r : res)
            cout<<r<<" ";
        cout<<" ";
    }
        
    return 0;
}