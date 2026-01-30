#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isCandidate(const vector<int> &nums, int threshold, int mid) {
    int currentSum = 0;

    for(int num : nums)
        currentSum += ceil(double(num) / mid);  // Ceiling Function

    return threshold >= currentSum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = *min_element(nums.begin(), nums.end()), mid = 0,
        high = *max_element(nums.begin(), nums.end()), divisor = 0;
    
    while(low <= high) {
        mid = low + (high - low) / 2;

        if(isCandidate(nums, threshold, mid)) {
            divisor = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return divisor;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout<<smallestDivisor(nums, threshold);

    return 0;
}