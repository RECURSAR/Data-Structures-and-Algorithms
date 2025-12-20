#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct IndexedQuery {
    int queryIndex;
    int a;  // Alice's index
    int b;  // Bob's index
};

vector<IndexedQuery> getIndexedQueries(const vector<vector<int>>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i) {
      int a = min(queries[i][0], queries[i][1]);
      int b = max(queries[i][0], queries[i][1]);
      indexedQueries.push_back({i, a, b});
    }

    sort(indexedQueries.begin(), indexedQueries.end(),
         [](const IndexedQuery& a, const IndexedQuery& b) { return a.b > b.b; });

    return indexedQueries;
}

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), -1);
    vector<int> stack;

    vector<IndexedQuery> indexedQueries = getIndexedQueries(queries);

    int heightsIndex = heights.size() - 1;

    for (const auto& indexedQuery : indexedQueries) {
      int queryIndex = indexedQuery.queryIndex;
      int a = indexedQuery.a;
      int b = indexedQuery.b;

      if (a == b || heights[a] < heights[b]) {
        ans[queryIndex] = b;
      } else {
        while (heightsIndex > b) {
          while (!stack.empty() && heights[stack.back()] <= heights[heightsIndex])
            stack.pop_back();
          stack.push_back(heightsIndex--);
        }

        auto it = upper_bound(stack.rbegin(), stack.rend(), a, [&](int a, int b) { return heights[a] < heights[b];});
        if (it != stack.rend())
          ans[queryIndex] = *it;
      }
    }

    return ans;
}

int main() {
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};

    vector<int> buildings = leftmostBuildingQueries(heights, queries);
    for(auto building : buildings)
        cout<<building<<" ";

    return 0;
}