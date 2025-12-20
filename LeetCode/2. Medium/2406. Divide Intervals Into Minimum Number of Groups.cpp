#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;

    for(const auto interval: intervals){
        events.push_back({interval[0], 1});         // Start of interval
        events.push_back({interval[1] + 1, -1});    // End of interval (+1 as it's inclusive)
    }

    sort(events.begin(), events.end());

    int maxGroups = 0, currGroups = 0;

    // Calculating maximum overlaps
    for(const auto event: events){
        currGroups += event.second;
        maxGroups = max(currGroups, maxGroups);
    }

    return maxGroups;
}

int main() {
    vector<vector<int>> intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}};

    cout<<minGroups(intervals);

    return 0;
}