#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, mid = 0, high = arr.size() - 1, missing = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        // This gives us the total number missing at that index
        missing = arr[mid] - (mid + 1);

        if(missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // At the end of the loop high is at the position where missing < k and low is at missing >= k
    return k + high + 1;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout<<findKthPositive(arr, k);

    return 0;
}