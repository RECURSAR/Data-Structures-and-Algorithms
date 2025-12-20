#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

enum class State { kInit, kVisiting, kVisited };

bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& states) {
    if (states[u] == State::kVisiting)
      return true;
    if (states[u] == State::kVisited)
      return false;

    states[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State::kVisited;

    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    vector<State> states(graph.size());

    for (int i = 0; i < graph.size(); ++i)
      if (!hasCycle(graph, i, states))
        ans.push_back(i);

    return ans;    
}

int main() {
    vector<vector<int>> graph = {{1,2}, {2,3}, {5}, {0}, {5}, {}, {}};

    vector<int> result = eventualSafeNodes(graph);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}