#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();

    // Events: (time, type, friend)
    vector<pair<int, pair<int, int>>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({times[i][0], {1, i}});  // Arrival event
        events.push_back({times[i][1], {0, i}});  // Departure event
    }

    // Sort events based on time. If times are the same, arrival event (1) comes before departure (0)
    sort(events.begin(), events.end());

    // Min-heap for available chairs
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    for (int i = 0; i < n; i++) {
        availableChairs.push(i);  // Initially, all chairs [0, 1, 2, ..., n-1] are available
    }

    // Min-heap to track departure times and the chairs that will be freed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving;

    // Array to store which chair each friend is sitting on
    vector<int> chairAssigned(n, -1);

    // Process all events
    for (auto& event : events) {
        int time = event.first;
        int type = event.second.first;
        int friendIndex = event.second.second;

        // Free chairs of friends who are leaving at the current time
        while (!leaving.empty() && leaving.top().first <= time) {
            int chairToFree = leaving.top().second;
            leaving.pop();
            availableChairs.push(chairToFree);  // Free up the chair
        }

        // If it's an arrival event
        if (type == 1) {
            int chair = availableChairs.top();  // Get the smallest available chair
            availableChairs.pop();              // Assign it and remove from available
            chairAssigned[friendIndex] = chair; // Store the chair for the friend
            leaving.push({times[friendIndex][1], chair});  // Track when this chair will be freed

            // If this is the target friend, return their chair number
            if (friendIndex == targetFriend) {
                return chair;
            }
        }
    }

    return -1;  // This line should never be reached
}

int main() {
    vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend = 1;

    cout << "Chair of target friend: " << smallestChair(times, targetFriend) << endl;

    return 0;
}
