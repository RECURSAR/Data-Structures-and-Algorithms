#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> ballToColor;
    unordered_map<int, int> colorCount;

    for (const vector<int>& query : queries) {
      const int ball = query[0];
      const int color = query[1];
      const auto it = ballToColor.find(ball);
      if (it != ballToColor.cend()) {
        const int prevColor = it->second;
        if (--colorCount[prevColor] == 0)
          colorCount.erase(prevColor);
      }
      ballToColor[ball] = color;
      ++colorCount[color];
      ans.push_back(colorCount.size());
    }

    return ans;    
}

int main() {
    int limit = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};

    vector<int> result;
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}