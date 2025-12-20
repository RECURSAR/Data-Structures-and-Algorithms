#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getStartNode(const unordered_map<int, stack<int>>& graph, unordered_map<int, int>& outDegree, unordered_map<int, int>& inDegrees,const vector<vector<int>>& pairs) {
    for (const auto& entry : graph) {
      const int u = entry.first;
      if (outDegree[u] - inDegrees[u] == 1)
        return u;
    }

    return pairs[0][0];  // Arbitrarily choose a node.
}

void euler(unordered_map<int, stack<int>>& graph, int u, vector<vector<int>>& ans) {
    auto& s = graph[u];

    while (!s.empty()) {
        const int v = s.top();
        s.pop();
        euler(graph, v, ans);
        ans.push_back({u, v});
    }
}

vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    vector<vector<int>> ans;
    unordered_map<int, stack<int>> graph;
    unordered_map<int, int> outDegree;
    unordered_map<int, int> inDegrees;

    for (const vector<int>& pair : pairs) {
      const int start = pair[0];
      const int end = pair[1];
      
      graph[start].push(end);
      ++outDegree[start];
      ++inDegrees[end];
    }

    const int startNode = getStartNode(graph, outDegree, inDegrees, pairs);
    euler(graph, startNode, ans);
    std::reverse(ans.begin(), ans.end());
    return ans;    
}

int main() {
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};

    vector<vector<int>> arrangement = validArrangement(pairs);
    for(auto arrange : arrangement){
        for(auto it : arrange)
            cout<<it<<" ";
        cout<<endl;
    }
        
    return 0;
}