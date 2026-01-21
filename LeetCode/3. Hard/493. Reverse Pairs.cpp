#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int mergeLike(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    int pairs = 0;
    int i = left, j = right;     // pointers for merge step

    // Count cross reverse pairs using two pointers
    for (int itr = low; itr <= mid; itr++) {
        // Move right pointer while condition holds
        while (right <= high && (long long)nums[itr] > 2LL * nums[right])
            right++;

        // All indices from mid+1 to right-1 satisfy condition
        pairs += (right - (mid + 1));
    }

    // Standard merge step to keep array sorted
    while(i <= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i += 1;
        }
        else {
            temp.push_back(nums[j]);
            j += 1;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i += 1;
    }

    while(j <= high) {
        temp.push_back(nums[j]);
        j += 1;
    }

    // Copy merged sorted elements back into original array
    for(size_t k = 0; k < temp.size(); k++)
        nums[left + k] = temp[k];

    return pairs;
}

int mergeSortLike(vector<int> &nums, int low, int high) {
    int pairs = 0, mid = 0;

    if(low >= high)
        return pairs;

    mid = (low + high) / 2;

    // Count pairs in left half
    pairs += mergeSortLike(nums, low, mid);

    // Count pairs in right half
    pairs += mergeSortLike(nums, mid + 1, high);

    // Count cross pairs and merge the two halves
    pairs += mergeLike(nums, low, mid, high);

    return pairs;
}

int reversePairs(vector<int>& nums) {
    return mergeSortLike(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};

    cout << reversePairs(nums);

    return 0;
}
