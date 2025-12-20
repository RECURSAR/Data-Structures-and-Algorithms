#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int toMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hours * 60 + minutes;
}

int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;

    for (auto time : timePoints)
        minutes.push_back(toMinutes(time));

    int minDiff = INT_MAX;
    sort(minutes.begin(), minutes.end());

    // Calculate differences between consecutive sorted times
    for (int i = 1; i < minutes.size(); i++)
        minDiff = min(minDiff, minutes[i] - minutes[i - 1]);

    // Calculate circular difference between the last and first time points
    int circularDiff = minutes[0] + 1440 - minutes.back();
    minDiff = min(circularDiff, minDiff);

    return minDiff;
}

int main() {
    vector<string> timePoints = {"23:59","00:00"};

    cout<<findMinDifference(timePoints);
    
    return 0;
}