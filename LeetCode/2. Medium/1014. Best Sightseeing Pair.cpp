#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int ans = 0;
    int bestPrev = 0;

    for (const int value : values) {
      ans = max(ans, value + bestPrev);
      bestPrev = max(bestPrev, value) - 1;
    }

    return ans;
}

int main() {
    vector<int> values = {8, 1, 5, 2, 6};

    cout<<maxScoreSightseeingPair(values);

    return 0;
}