#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int firstIndexPosition(vector<int> &arr, int target) {
    int low = 0, mid = 0, high = arr.size() - 1, firstIndex = -1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(arr[mid] >= target) {
            if(arr[mid] == target)
                firstIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return firstIndex;
}

int lastIndexPosition(vector<int> &arr, int target) {
    int low = 0, mid = 0, high = arr.size() - 1, lastIndex = -1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(arr[mid] <= target) {
            if(arr[mid] == target)
                lastIndex = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return lastIndex;
}

int countFreq(vector<int>& arr, int target) {
    int firstIndex = 0, lastIndex = 0;

    firstIndex = firstIndexPosition(arr, target);
    lastIndex = lastIndexPosition(arr, target);

    if(firstIndex == -1 && lastIndex == -1)
        return 0;

    return lastIndex - firstIndex + 1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;

    cout<<countFreq(arr, target);

    return 0;
}