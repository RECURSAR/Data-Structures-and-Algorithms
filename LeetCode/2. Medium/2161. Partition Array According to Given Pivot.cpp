#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans;

    for (const int num : nums)
      if (num < pivot)
        ans.push_back(num);

    for (const int num : nums)
      if (num == pivot)
        ans.push_back(num);

    for (const int num : nums)
      if (num > pivot)
        ans.push_back(num);

    return ans;       
}

int main() {
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;

    vector<int> result = pivotArray(nums, pivot);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}