#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Worst Case - O(N)
/*
vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, mid = -1, high = nums.size() - 1, startIndex = 0, endIndex = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (nums[mid] == target)
            break;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (mid == -1 || low > high)
        return {-1, -1};

    startIndex = mid;
    endIndex = mid;

    while (startIndex >= 0 && nums[startIndex] == target)
        startIndex -= 1;

    while (endIndex < nums.size() && nums[endIndex] == target)
        endIndex += 1;

    return {startIndex + 1, endIndex - 1};
}
*/

// Optimal Approach
int findFirstPosition(vector<int> &nums, int target) {
    int low = 0, mid = 0, high = nums.size() - 1, firstIndex = -1;

    while(low <= high) {
        /*
        mid should be calculated using (low + (high - low) / 2) since it avoids overflow, otherwise it does the same to what
        (low + high) / 2 does
        */
        mid = (low + high) / 2;

        if(nums[mid] >= target) {
            if(nums[mid] == target)
                firstIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return firstIndex;
}

int findLastPosition(vector<int> &nums, int target) {
    int low = 0, mid = 0, high = nums.size() - 1, lastIndex = -1;

    while(low <= high) {
        /*
        mid should be calculated using (low + (high - low) / 2) since it avoids overflow, otherwise it does the same to what
        (low + high) / 2 does
        */
        mid = (low + high) / 2;

        if(nums[mid] <= target) {
            if(nums[mid] == target)
                lastIndex = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return lastIndex;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {findFirstPosition(nums, target), findLastPosition(nums, target)};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);
    for(auto num : result)
        cout<<num<<" ";

    return 0;
}