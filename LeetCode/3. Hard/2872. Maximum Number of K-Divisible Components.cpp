#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long dfs(const vector<vector<int>>& graph, int u, int prev, const vector<int>& values, int k, int& ans) {
    long treeSum = values[u];

    for (const int v : graph[u])
      if (v != prev)
        treeSum += dfs(graph, v, u, values, k, ans);

    if (treeSum % k == 0)
      ++ans;

    return treeSum;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    int ans = 0;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, /*prev=*/-1, values, k, ans);
    return ans; 
}

int main() {
    int n = 5, k = 6;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};

    cout<<maxKDivisibleComponents(n, edges, values, k);

    return 0;
}