#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst) {
    constexpr int kMod = 1'000'000'007;
    vector<long> ways(graph.size());
    vector<long> dist(graph.size(), LONG_MAX);

    ways[src] = 1;
    dist[src] = 0;
    using P = pair<long, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto top = minHeap.top();
      const long d = top.first;
      const int u = top.second;
      minHeap.pop();
      if (d > dist[u])
        continue;
      for (const auto& edge : graph[u]) {
        int v = edge.first;
        int w = edge.second;
        if (d + w < dist[v]) {
          dist[v] = d + w;
          ways[v] = ways[u];
          minHeap.emplace(dist[v], v);
          } else if (d + w == dist[v]) {
            ways[v] += ways[u];
            ways[v] %= kMod;
          }
        }
    }

    return ways[dst];
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      const int w = road[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, 0, n - 1);
}

int main() {
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};

    cout<<countPaths(n, roads);

    return 0;
}