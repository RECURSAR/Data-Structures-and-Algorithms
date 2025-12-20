#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxSubArray(vector<int>& nums) {
    int localSum = 0, maxSum = INT_MIN;

    for(auto num : nums) {
        if(localSum < 0)
            localSum = 0;
        
        localSum += num;
        maxSum = max(maxSum, localSum);
    }

    return maxSum;
}

// Printing the Maximum Sub-Array
// vector<int> maxSumSubarray(vector<int>& arr) {
//     int localSum = 0, maxSum = INT_MIN;
//     int startIndex = 0, lastIndex = 0;
//     int tempStart = 0;
//     vector<int> result;

//     for (int i = 0; i < arr.size(); i++) {
//         // If current sum is negative, discard it
//         if (localSum < 0) {
//             localSum = 0;
            
//             // tempStart keeps track of where the current running subarray starts, 
//             // while startIndex stores where the best subarray starts.
//             tempStart = i;
//         }

//         localSum += arr[i];

//         // Update maximum sum and indices
//         if (localSum > maxSum) {
//             maxSum = localSum;
//             startIndex = tempStart;
//             lastIndex = i;
//         }
//     }

//     // Build the result subarray
//     for (int i = startIndex; i <= lastIndex; i++)
//         result.push_back(arr[i]);

//     return result;
// }

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout<<maxSubArray(nums);

    return 0;
}