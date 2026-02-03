#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canBePlaced(vector<int> &stalls, int k, int space) {
    int count = 1, lastStall = stalls[0];

    for(size_t i = 1; i < stalls.size(); i++) {
        if(stalls[i] - lastStall >= space) {
            count += 1;
            lastStall = stalls[i];
        }    
    }

    return count >= k;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1, mid = 0, high = stalls.back() - stalls.front(), maxMinDistance = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(canBePlaced(stalls, k, mid)) {
            maxMinDistance = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return maxMinDistance;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout<<aggressiveCows(stalls, k);

    return 0;
}