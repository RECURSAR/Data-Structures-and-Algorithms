#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countMerged(vector<pair<int, int>>& intervals) {
    int count = 0;
    int prevEnd = 0;

    std::sort(intervals.begin(), intervals.end());

    for (const auto& interval : intervals) {
        int start = interval.first;
        int finish = interval.second;
        if (start < prevEnd) {
            prevEnd = max(prevEnd, finish);
        } else {
            prevEnd = finish;
            ++count;
        }
    }

    return count;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> xs;
    vector<pair<int, int>> ys;

    for (const vector<int> rectangles : rectangles) {
      const int startX = rectangles[0];
      const int startY = rectangles[1];
      const int endX = rectangles[2];
      const int endY = rectangles[3];
      xs.emplace_back(startX, endX);
      ys.emplace_back(startY, endY);
    }

    return max(countMerged(xs), countMerged(ys)) >= 3;  
}

int main() {
    int n = 5;
    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};

    checkValidCuts(n, rectangles) ? cout<<"True" : cout<<"False";

    return 0;
}