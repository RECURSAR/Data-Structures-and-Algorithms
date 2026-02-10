#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using Priority Queue - Better Approach
/*
double minMaxDist(vector<int> &stations, int K) {
    if(stations.size() == 1)
        return 0.00;

    int segmentIndex = 0;
    long double length = 0, totalDistance = 0, newLength = 0;
    vector<int> howMany(stations.size() - 1, 0);
    priority_queue<pair<long double, int>> pq;
    pair<long double, int> top;

    // Populating Priority Queue
    for(size_t i = 0; i < stations.size() - 1; i++) {
        length = stations[i + 1] - stations[i];
        pq.push({length, i});
    }

    // Placing K gas stations
    for(int gasStation = 1; gasStation <= K; gasStation += 1) {
        top = pq.top();
        pq.pop();
        segmentIndex = top.second;

        // Add station to the largest segment and update the segments length
        howMany[segmentIndex] += 1;
        totalDistance = stations[segmentIndex + 1] - stations[segmentIndex];
        newLength = totalDistance / (howMany[segmentIndex] + 1);

        pq.push({newLength, segmentIndex});
    }

    return pq.top().first;
}
*/

// Optimal Approach using Binary Search

// Given a candidate maximum distance `distance`, it computes how many extra gas stations are needed so that
// no adjacent stations are more than `distance` apart.
int numberOfGasStationsRequired(vector<int> &stations, long double distance) {
    int count = 0, numbersInBetween = 0;

    for(int i = 1; i < stations.size(); i++) {
        // Length of the current segment
        numbersInBetween = (stations[i] - stations[i - 1]) / distance;

        // If the segment is exactly divisible, we subtract 1 because placing exactly at the end 
        // does NOT create an extra segment.
        if((stations[i] - stations[i - 1]) == (distance * numbersInBetween))
            numbersInBetween -= 1;
        
        count += numbersInBetween;
    }

    return count;
}

double minMaxDist(vector<int> &stations, int K) {
    int count = 0;
    long double low = 0, mid = 0, high = 0, minMaxDistance = 0, DIFF = 1e-6;

    // Largest Segment in Array
    for(size_t i = 0; i < stations.size() - 1; i++)
        if(stations[i] < stations[i + 1])
            high = max(high, (long double)stations[i + 1]);

    while(high - low > DIFF) {
        mid = low + (high - low) / 2.00;

        // How many stations are needed if max distance is `mid`
        count = numberOfGasStationsRequired(stations, mid);

        if(count <= K) {
            minMaxDistance = mid;
            high = mid;
        }
        else
            low = mid;
    }

    return minMaxDistance;
}

int main() {
    vector<int> stations = {1, 2, 3, 4, 5};
    int K = 2;

    cout<<minMaxDist(stations, K);

    return 0;
}