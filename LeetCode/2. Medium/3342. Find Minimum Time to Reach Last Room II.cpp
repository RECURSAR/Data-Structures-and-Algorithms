#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int dijkstra(const vector<vector<int>>& moveTime, const pair<int, int>& src, const pair<int, int>& dst) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = moveTime.size();
    const int n = moveTime[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    dist[0][0] = 0;
    using T = pair<int, pair<int, int>>;  // (d, (ux, uy))
    priority_queue<T, vector<T>, greater<>> minHeap;
    minHeap.push({dist[0][0], src});

    while (!minHeap.empty()) {
        const auto current = minHeap.top();
        minHeap.pop();
        const int d = current.first;
        const auto u = current.second;

        if (u == dst)
            return d;

        const int i = u.first;
        const int j = u.second;

        if (d > dist[i][j])
            continue;

        for (const auto& dir : kDirs) {
            const int x = i + dir[0];
            const int y = j + dir[1];

            if (x < 0 || x == m || y < 0 || y == n)
                continue;

            const int newDist = max(moveTime[x][y], d) + ((i + j) % 2 + 1);
            
            if (newDist < dist[x][y]) {
                dist[x][y] = newDist;
                minHeap.push({newDist, {x, y}});
            }
        }
    }

    return -1;
}

int minTimeToReach(vector<vector<int>>& moveTime) {
    return dijkstra(moveTime, {0, 0}, {moveTime.size() - 1, moveTime[0].size() - 1});
}

int main() {
    vector<vector<int>> moveTime = {{0,4},{4,4}};
    
    cout<<minTimeToReach(moveTime);

    return 0;
}