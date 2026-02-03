#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canBeAlloted(vector<int> &arr, int k, int pages) {
    int students = 1, currentPages = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        if(currentPages + arr[i] > pages) {
            currentPages = 0;
            students += 1;

            if(students > k)
                return false;
        }

        currentPages += arr[i];
    }

    return true;
}

int findPages(vector<int> &arr, int k) {
    if(arr.size() < k)
        return -1;

    int low = *max_element(arr.begin(), arr.end()), mid = 0, 
        high = accumulate(arr.begin(), arr.end(), 0), minMaxPages = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(canBeAlloted(arr, k, mid)) {
            minMaxPages = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return minMaxPages;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    cout<<findPages(arr, k);

    return 0;
}