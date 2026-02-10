#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canBePainted(vector<int> &boards, int k, int maxTime) {
    int currentTime = 0, painters = 1;

    for(size_t i = 0; i < boards.size(); i++) {
        if(currentTime + boards[i] > maxTime) {
            currentTime = 0;
            painters += 1;

            if(painters > k)
                return false;
        }

        currentTime += boards[i];
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end()), mid = 0,
        high = accumulate(boards.begin(), boards.end(), 0), minMaxTime = 0;
    
    while(low <= high) {
        mid = low + (high - low) / 2;
        
        if(canBePainted(boards, k, mid)) {
            minMaxTime = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return minMaxTime;
}

int main() {
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;

    cout<<findLargestMinDistance(boards, k);

    return 0;
}