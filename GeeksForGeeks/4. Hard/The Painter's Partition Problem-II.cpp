#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canBePainted(vector<int> &arr, int k, int maxTime) {
    int currentTime = 0, painters = 1;

    for(size_t i = 0; i < arr.size(); i++) {
        if(currentTime + arr[i] > maxTime) {
            currentTime = 0;
            painters += 1;

            if(painters > k)
                return false;
        }

        currentTime += arr[i];
    }

    return true;
}

int minTime(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end()), mid = 0, 
        high = accumulate(arr.begin(), arr.end(), 0), minMaxTime = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(canBePainted(arr, k, mid)) {
            minMaxTime = mid;
            high = mid - 1;
        }    
        else
            low = mid + 1;
    }

    return minMaxTime;
}

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;
    
    cout<<minTime(arr, k);

    return 0;
}