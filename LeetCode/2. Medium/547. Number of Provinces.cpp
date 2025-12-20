#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void createGraph(const vector<vector<int>>& isConnected, unordered_map<int, vector<int>>& graph);

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited);
        }
    }
}

int findCircleNum(const vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<vector<int>> adj(V);

    // Making an adjacency list from adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);
    int provinces = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << "Number of provinces: " << findCircleNum(isConnected) << endl;

    return 0;
}

void createGraph(const vector<vector<int>>& isConnected, unordered_map<int, vector<int>>& graph) {
    int n = isConnected.size();

    // Iterate through the matrix and build the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If there's a connection between city i and city j, add it to the graph
            if (isConnected[i][j] == 1 && i != j) {
                graph[i].push_back(j);
                graph[j].push_back(i); // Since it's an undirected graph
            }
        }
    }
}