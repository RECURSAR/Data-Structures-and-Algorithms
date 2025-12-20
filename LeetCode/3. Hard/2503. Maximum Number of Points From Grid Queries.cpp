#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct IndexedQuery {
    int queryIndex;
    int query;
};
  
struct T {
    int i;
    int j;
    int val;  // grid[i][j]
};

vector<IndexedQuery> getIndexedQueries(const vector<int>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexedQueries.push_back({i, queries[i]});
    std::sort(
        indexedQueries.begin(), indexedQueries.end(),
        [](const IndexedQuery& a, const IndexedQuery& b) { return a.query < b.query; });
    return indexedQueries;
}
  
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> ans(queries.size());
    auto compare = [](const T& a, const T& b) { return a.val > b.val; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    vector<vector<bool>> seen(m, vector<bool>(n));

    minHeap.emplace(0, 0, grid[0][0]);
    seen[0][0] = true;
    int accumulate = 0;

    for (const auto& indexedQuery : getIndexedQueries(queries)) {
    int queryIndex = indexedQuery.queryIndex;
    int query = indexedQuery.query;
    while (!minHeap.empty()) {
        const T& top = minHeap.top();
        int i = top.i;
        int j = top.j;
        int val = top.val;
        minHeap.pop();
        if (val >= query) {
        // The smallest neighbor is still larger than `query`, so no need to
        // keep exploring. Re-push (i, j, grid[i][j]) back to the `minHeap`.
        minHeap.emplace(i, j, val);
        break;
        }
        ++accumulate;
        for (const auto& dir : kDirs) {
        const int dx = dir[0];
        const int dy = dir[1];
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
            continue;
        if (seen[x][y])
            continue;
        minHeap.emplace(x, y, grid[x][y]);
        seen[x][y] = true;
        }
    }
    ans[queryIndex] = accumulate;
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries = {3};

    vector<int> result = maxPoints(grid, queries);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}