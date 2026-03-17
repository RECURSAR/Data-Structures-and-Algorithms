#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isSafe(int node, int color, vector<vector<int>> &adj, vector<int> &colors) {
    for(int neighbour : adj[node])
        if(colors[neighbour] == color)
            return false;
    
    return true;
}

bool solve(int node, int v, int m, vector<vector<int>> &adj, vector<int> &colors) {
    if(node == v)
        return true;
    
    for(int color = 1; color <= m; color++) {
        if(isSafe(node, color, adj, colors)) {
            colors[node] = color;

            if(solve(node + 1, v, m, adj, colors))
                return true;
            
            // Backtrack
            colors[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<vector<int>> adj(v);
    vector<int> colors(v, 0);

    // Making adjacency list
    for(auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return solve(0, v, m, adj, colors);
}

int main() {
    int v = 4, m = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};

    graphColoring(v, edges, m) ? cout<<"True" : cout<<"False";

    return 0;
}