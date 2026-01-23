#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int upperBound(vector<int>& arr, int target) {
    int low = 0, mid = 0, high = arr.size() - 1, upperBound = arr.size();

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] > target) {
            upperBound = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return upperBound;
}

int main() {
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int target = 9;

    cout<<upperBound(arr, target);

    return 0;
}