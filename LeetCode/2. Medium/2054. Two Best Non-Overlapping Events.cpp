#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct  Event
{
    int time;
    int value;
    int isStart;
};

int maxTwoEvents(vector<vector<int>>& events) {
    int ans = 0;
    int maxValue = 0;
    vector<Event> evts;

    for (const vector<int>& event : events) {
      const int start = event[0];
      const int end = event[1];
      const int value = event[2];
      evts.emplace_back(start, value, true);
      evts.emplace_back(end + 1, value, false);
    }

    std::sort(evts.begin(), evts.end(), [](const Event& a, const Event& b) {
      return a.time == b.time ? a.isStart < b.isStart : a.time < b.time;
    });

    for (const auto& evt : evts)
      if (evt.isStart)
        ans = max(ans, evt.value + maxValue);
      else
        maxValue = max(maxValue, evt.value);

    return ans;
}

int main() {
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};

    cout<<maxTwoEvents(events);

    return 0;
}