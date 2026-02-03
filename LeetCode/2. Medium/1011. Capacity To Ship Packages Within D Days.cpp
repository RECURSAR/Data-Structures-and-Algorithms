#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool meetsDeadline(vector<int> &weights, int days, int maxWeight) {
    int currentDays = 1, currentWeight = 0;

    for(int weight : weights) {
        if(currentWeight + weight > maxWeight) {
            currentDays += 1;
            currentWeight = 0;
        }

        currentWeight += weight;
    }

    return currentDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end()), mid = 0,
        high = accumulate(weights.begin(), weights.end(), 0), minimumWeight = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(meetsDeadline(weights, days, mid)) {
            minimumWeight = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return minimumWeight;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;    

    cout<<shipWithinDays(weights, days);

    return 0;
}