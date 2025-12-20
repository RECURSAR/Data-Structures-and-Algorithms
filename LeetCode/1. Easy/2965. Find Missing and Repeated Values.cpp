#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int nSquared = n * n;
    vector<int> count(nSquared + 1);

    for (const vector<int>& row : grid)
      for (const int num : row)
        ++count[num];

    int repeated = -1;
    int missing = -1;

    for (int i = 1; i <= nSquared; ++i) {
      if (count[i] == 2)
        repeated = i;
      if (count[i] == 0)
        missing = i;
    }

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {{1,3}, {2,2}};

    vector<int> result = findMissingAndRepeatedValues(grid);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}