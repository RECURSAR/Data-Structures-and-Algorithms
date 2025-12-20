#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Performs a BFS to update the shortest distances from the given `start` node
// to all other reachable nodes in the graph. It updates the `dist` vector
// with the new shortest distances.
void bfs(const vector<vector<int>>& graph, int start, vector<int>& dist) {
    queue<int> q{{start}};

    while (!q.empty()) {
        const int u = q.front();
        q.pop();

        for (const int v : graph[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> dist(n);
    vector<vector<int>> graph(n);

    iota(dist.begin(), dist.end(), 0);

    for (int i = 0; i < n - 1; ++i)
        graph[i].push_back(i + 1);

    for (const vector<int>& query : queries) {
        const int u = query[0];
        const int v = query[1];
        graph[u].push_back(v);

        if (dist[u] + 1 < dist[v]) {
            dist[v] = dist[u] + 1;
            bfs(graph, v, dist);
        }
        
        ans.push_back(dist[n - 1]);
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};

    vector<int> distance = shortestDistanceAfterQueries(n, queries);
    for(auto dis: distance)
        cout<<dis<<" ";

    return 0;
}