#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    int firstElement = INT_MIN, secondElement = INT_MIN;
    int count1 = 0, count2 = 0, mini = (int)(nums.size() / 3) + 1;

    // At max there can only be two elements in the resultant array since we only need elements
    // which have frequency more than n/3

    // Boyer-Moore - Pairwise Cancellation
    for(size_t i = 0; i < nums.size(); i++) {
        // Keeping sure that the current element is not equal to second element since for that we are
        // already maintaining a separate count called count2
        if(count1 == 0 && nums[i] != secondElement) {
            count1 = 1;
            firstElement = nums[i];
        }
        // Keeping sure that the current element is not equal to first element since for that we are
        // already maintaining a separate count called count1
        else if(count2 == 0 && nums[i] != firstElement) {
            count2 = 1;
            secondElement = nums[i];
        }
        else if(nums[i] == firstElement)
            count1 += 1;
        else if(nums[i] == secondElement)
            count2 += 1;
        else {
            count1 -= 1;
            count2 -= 1;
        }
    }

    // The output of previous loop will give us candidates which might have count > n/3, we will still have to
    // validate that. For eg:- {1,2,3,4,5,6,7}. The output after the first loop will give us firstElement as 6
    // and secondElement as 7, both of them have count < n/3, so they will not go into the result array.

    count1 = 0; count2 = 0;
    for(auto num : nums) {
        if(firstElement == num)
            count1 += 1;
        if(secondElement == num)
            count2 += 1;
    }

    // Only pushing elements which have count >= n/3
    if(count1 >= mini)
        result.push_back(firstElement);
    if(count2 >= mini)
        result.push_back(secondElement);

    return result;
}

int main() {
    vector<int> nums = {3, 2, 3};

    vector<int> result = majorityElement(nums);

    for(auto num : result)
        cout<<num<<" ";

    return 0;
}