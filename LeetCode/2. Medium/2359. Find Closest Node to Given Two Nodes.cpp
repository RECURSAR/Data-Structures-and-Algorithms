#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void dfs(int current, int distance, const vector<int>& edges, vector<int>& distances) {
    while (current != -1 && distances[current] == -1) {
        distances[current] = distance++;
        current = edges[current];
    }
}

int closestMeetingNode(vector<int>& edges, int start1, int start2) {
    int res = -1, Min_Of_Max = INT_MAX, n = edges.size();
    vector<int> dist1(n, -1), dist2(n, -1);
    dfs(start1, 0, edges, dist1);
    dfs(start2, 0, edges, dist2);

    for (int i = 0; i < n; i++) {
        if (dist1[i] >= 0 && dist2[i] >= 0) {
            int maxDist = max(dist1[i], dist2[i]);
            if (maxDist < Min_Of_Max) {
                Min_Of_Max = maxDist;
                res = i;
            }
        }
    }
    
    return res;
}

int main() {
    vector<int> edges = {2,2,3,-1};
    int node1 = 0, node2 = 1;
    
    cout<<closestMeetingNode(edges, node1, node2);

    return 0;
}