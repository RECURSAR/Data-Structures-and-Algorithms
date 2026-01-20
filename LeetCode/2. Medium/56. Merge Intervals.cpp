#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end());

    for(size_t i = 0; i < intervals.size(); i++) {
        if(result.empty() || result.back()[1] < intervals[i][0])
            result.push_back({intervals[i][0], intervals[i][1]});
        else
            result.back()[1] = max(result.back()[1], intervals[i][1]);
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};    

    vector<vector<int>> result = merge(intervals);
    for(auto row : result) {
        for(auto num : row)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}