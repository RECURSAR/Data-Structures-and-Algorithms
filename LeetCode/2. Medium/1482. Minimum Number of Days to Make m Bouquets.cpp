#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canMake(const vector<int> &bloomDay, int m, int k, int day) {
    int bouquets = 0, adjacentFlowers = 0;

    for(int flowers : bloomDay) {
        if(flowers <= day) {
            adjacentFlowers += 1;
            if(adjacentFlowers == k) {
                bouquets += 1;
                adjacentFlowers = 0;
            }
        }
        else
            adjacentFlowers = 0;
    }

    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if(bloomDay.size() < (long long)m * k)
        return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end()), mid = 0,
        high = *max_element(bloomDay.begin(), bloomDay.end()), days = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(canMake(bloomDay, m, k, mid)) {
            days = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return days;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    
    cout<<minDays(bloomDay, m, k);

    return 0;
}