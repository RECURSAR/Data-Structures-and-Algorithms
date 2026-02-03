#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isValidSplit(vector<int> &arr, int k, int maxSum) {
    int count = 1, currentSum = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        if(currentSum + arr[i] > maxSum) {
            currentSum = 0;
            count += 1;

            if(count > k)
                return false;
        }
        
        currentSum += arr[i];
    }
    
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end()), mid = 0,
        high = accumulate(nums.begin(), nums.end(), 0), minMaxSum = 0;
        
    while(low <= high) {
        mid = low + (high - low) / 2;

        if(isValidSplit(nums, k, mid)) {
            minMaxSum = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return minMaxSum;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout<<splitArray(nums, k);

    return 0;
}