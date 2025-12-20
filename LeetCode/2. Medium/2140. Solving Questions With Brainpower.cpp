#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    const int n = questions.size();
    // dp[i] := the maximum points starting from questions[i]
    vector<long> dp(n + 1);

    for (int i = n - 1; i >= 0; --i) {
      const int points = questions[i][0];
      const int brainpower = questions[i][1];
      const int nextIndex = i + brainpower + 1;
      const long nextPoints = nextIndex < n ? dp[nextIndex] : 0;
      dp[i] = max(points + nextPoints, dp[i + 1]);
    }

    return dp[0];     
}

int main() {
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};

    cout<<mostPoints(questions);

    return 0;
}